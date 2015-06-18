<?php

include_once __DIR__ . '/../eif-fragments-inc.php';

class EifTest extends PHPUnit_Framework_TestCase
{
  var $sitemap = array();
  var $manuscripts = array();
  var $paths_of_interest = array();
  var $offset = 0;
  var $limit = 0;
  var $problems = array();

  public function setUp()
  {
  	$this->setManuscripts();
  }

  public function tearDown(){}

  private function setSitemap()
  {
    if (empty($this->sitemap))
    {
      $sitemap = file(__DIR__ . '/sitemap.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
      foreach ($sitemap as $item) {
        if ($manuscript_id = substr($item, 11, 5)) {
          $this->sitemap[$manuscript_id][] = $item;
        }
      }
    }
  }

  private function setManuscripts()
  {
    if (empty($this->manuscripts))
    {
      $this->manuscripts = file(__DIR__ . '/manuscripts.txt', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
      if ($this->limit > 0)
      {
        $this->manuscripts = array_slice($this->manuscripts, $this->offset, $this->limit);
      }
      $this->setSitemap();
      foreach ($this->manuscripts as $manuscript_id)
      {
        if (!empty($this->sitemap[$manuscript_id]))
        {
          foreach ($this->sitemap[$manuscript_id] as $path)
          {
            if (strpos($path, '/e' . $manuscript_id) !== FALSE)
            {
              $this->paths_of_interest[$manuscript_id][] = $path;
            }
          }
        }
      }
    }
  }

  /**
   * @dataProvider provider
   */
  public function testArticlePath($manuscript_id)
  {
    $input = "https://s3.amazonaws.com/elife-cdn/elife-articles/{$manuscript_id}/elife{$manuscript_id}.xml";

    $xml = simplexml_load_file($input);

    $volume = $xml->xpath('//article-meta/volume')[0];
    $publisher_id = $xml->xpath('//article-meta/article-id[@pub-id-type="publisher-id"]')[0];
    $url_prefix = 'content/' . $volume . '/e' . $publisher_id;
    $fragments = xml_parse_fragments($xml, $url_prefix);
    foreach ($fragments as $fragment)
    {
      if (isset($fragment['path']) && !in_array($fragment['path'], $this->problems))
      {
        if(!empty($this->paths_of_interest[$manuscript_id]) && ($key = array_search($fragment['path'], $this->paths_of_interest[$manuscript_id])) !== FALSE) {
          unset($this->paths_of_interest[$manuscript_id][$key]);
        }
        $found = in_array($fragment['path'], $this->sitemap[$manuscript_id]);
        switch ($fragment['type'])
        {
          case 'boxed-text':
            $this->assertFalse($found, $fragment['path'] . ' is found for ' . $manuscript_id);
            break;

          default:
            $this->assertTrue($found, $fragment['path'] . ' is not found for ' . $manuscript_id);
            break;
        }
      }
    }
    $this->pathsOfInterest($manuscript_id);
  }

  public function provider()
  {
    $this->setManuscripts();
    $manuscripts = $this->manuscripts;
    foreach ($manuscripts as $key => $manuscript_id) {
      $manuscripts[$key] = array($manuscript_id);
    }
    return $manuscripts;
  }

  private function pathsOfInterest($manuscript_id) {
    $pathsOfInterest = __DIR__ . '/pathsOfInterest/' . $manuscript_id . '.txt';
    if (file_exists($pathsOfInterest))
    {
      unlink($pathsOfInterest);
    }
    if (!empty($this->paths_of_interest[$manuscript_id]))
    {
      file_put_contents($pathsOfInterest, implode("\n", $this->paths_of_interest[$manuscript_id]));
    }
  }
}

Instructions

- cd php-sraper-figures
- php ./eif-fragments-example.php > output-to-file.json
- cat output-to-file.json

Line 5 of eif-fragments-example.php gives easy instructions to target the XML of any article.
Line 9 of eif-fragments-example.php gives easy instructions to allow the preferred paths to be output too.
Line 12 of eif-fragments-example.php gives easy instructions to allow the paths to be validated against the existing site

Example output:
- 02304.json
  - contains the only example of a grandchild fragment (content/3/e02304/F3/F5/DC1)
- 05502.json
  - contains an example of a fragment within a boxed-text element (content/4/e05502/F12)
  - it would be tempting to generate a path which included the /B1/ but HW have not been allocating content paths for boxed-text fragments so we will need to be able to generate the existing paths of fragments within boxed-text so we can generate 301 redirects. The path "should" be content/4/e05502/B1/F12.
- 05849.json
  - contains an example of a fragment within a boxed-text element (content/4/e05849/F5)
  - see note for 05502.json
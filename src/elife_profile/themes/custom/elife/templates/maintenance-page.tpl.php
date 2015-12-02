<!DOCTYPE html>

<html>

<head>

  <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
  <meta name="viewport"
        content="width=device-width, initial-scale=1, maximum-scale=10, minimum-scale=1, user-scalable=yes"/>

  <title>eLife</title>

  <style>

    body {
      background-color: rgb(255, 255, 255);
      color: rgb(86, 86, 86);
      font-family: Helvetica, Arial, Verdana, sans-serif;
      font-size: 1.25em;
      line-height: 1.5;
      margin: 0;
      text-align: center;
    }

    .message {
      position: absolute;
      top: 40%;
      left: 50%;
      -ms-transform: translateX(-50%) translateY(-40%);
      -webkit-transform: translate(-50%, -40%);
      transform: translate(-50%, -40%);
      width: 90%;
    }

    img {
      margin: 0 0 2em;
      max-width: 80%;
    }

    h1, p {
      font-size: 1em;
      margin: 0;
    }

  </style>

</head>

<body>

<div class="message">

  <img
    src="<?php print base_path() . drupal_get_path('theme', 'elife_maintenance') . '/images/logo.png'; ?>"
    alt="eLife">

  <h1>Site&nbsp;under maintenance</h1>

  <p>We should be back&nbsp;shortly. Thank&nbsp;you
    for&nbsp;your&nbsp;patience</p>

</div>

</body>

</html>

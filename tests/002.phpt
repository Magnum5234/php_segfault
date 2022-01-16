--TEST--
test1() Basic test
--EXTENSIONS--
segfault
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension segfault is loaded and working!
NULL

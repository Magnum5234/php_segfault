--TEST--
Check if segfault is loaded
--EXTENSIONS--
segfault
--FILE--
<?php
echo 'The extension "segfault" is available';
?>
--EXPECT--
The extension "segfault" is available

--TEST--
kkthxbye() Basic test
--EXTENSIONS--
segfault
--FILE--
<?php
echo "before";
kkthxbye();
echo "after";
--EXPECTF--
before
%s

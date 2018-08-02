<?php

$dir = ".";
$handle = opendir($dir);
//var_dump($handle);
while(($file = readdir($handle)) !== false){
    echo $file."\n";
}
iss533535353535353535353535353535353535353535353535353535353535353535353535353535353535353535353535353535353535
hotfix2

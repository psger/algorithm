<?php
function get_dir_info($path){
if($handle = opendir($path)){
    while (false !== ($file = readdir($handle))){
      if((is_dir($path."/".$file) && $file != "." && $file != ".."))
      {
        get_dir_info($path."/".$file."/");
      }
      else{
        if($file != "." && $file != "..")
        {
          echo $file."\n";
        }
      }
    }
    closedir($handle);
    }
}

$pa = ".";
get_dir_info($pa);

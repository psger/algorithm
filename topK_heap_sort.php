<?php
ini_set('memory_limit', '2048M');

function swap($a, $b){
  $tmp = $a;
  $a = $b;
  $b = $tmp;
}

//生成最小堆
function MinHeap(&$arr, $idx){
  $left = 2 * $idx + 1;
  echo $left;
  $right = 2 * $idx + 2;
  if(!$arr[$left]){
    return;
  }
    if($arr[$right] && $arr[$right] < $arr[$left]){
      $l = $right;
    }
      else $l = $left;
      if($arr[$idx] > $arr[$l])
        swap($arr[$idx], $arr[$l]);
        MinHeap($arr, $l);
}


//生成500w个数
for($i = 0; $i < 50; $i++){
  $num[] = $i;
}

//打乱
shuffle($num);

//先取出十个到数组
$topArr = array_slice($num, 0, 10);

//获取最后一个有子节点的索引的位置
$idx = floor(count($topArr) / 2) - 1;

//生成最小顶堆
for($i = $idx; $i >=0; $i--){
    MinHeap($topArr, $i);
}

//后面的直接比较顶部
//var_dump(time());

for($i = count($topArr); $i < count($num); $i++){
  if($num[$i] > $topArr[0]){
    $topArr[0] = $num[$i];
    MinHeap($topArr,0);
  }
}

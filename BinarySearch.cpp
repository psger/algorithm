#include <iostream>

int BinarySearch(int array[], int n, int value){
  int left = 0;
  int right = n - 1;

  while(left <= right){//注意此处的边界为什么要等于？只有一个元素的时候
    int middle = left + ((right - left) >> 1);//>> 1(二进制右移动一位相当于/2) 或者(right-left) / 2 + left 不会溢出
    if(array[middle] > value)
      right = middle - 1;
      else if(array[middle] < value)
      left = middle + 1;
      else
      return middle;

  }
  return -1;
}

//递归写法
int BinarySearch2(int array[], int start, int end, int key){
  int middle = (end - start) >> 1 + start;
  if(middle == key)
  return middle;
  if(end <= start){
    return -1
  }
  else if(key > middle){
    return BinarySearch2(array[], middle + 1, end, key);
  }
  else if(key < middle){
    return BinarySearch2(array[], start, middle - 1, key);
  }
  return -1;
}

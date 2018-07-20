#include <iostream>

int binarySearch(int array[], int n, int target){

}



int BinarySearch(int array[], int n, int value){
  int left = 0;
  int right = n - 1;

  while(left <= right){//注意此处的边界 
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
  int middle = (right - left) >> 1 + left;
  if(middle == key)
  return middle;
  if(end <= start){
    return -1
  }
  else if(key > middle){
    return BinarySearch2(array[], middle + 1, end);
  }
  else if(key < middle){
    return BinarySearch2(array[], start, middle - 1);
  }
  return -1;
}

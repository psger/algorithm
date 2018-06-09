#include<iostream>
using namespace std;


static void swap(int *a, int *b)//a,b都是地址
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int partition(int arr[], int left, int right)
{
  int i = left;
  int j = right;

  int pivot = arr[left];

  while(i < j){
    while(i < j && arr[j] >= pivot){
      --j;
    }
    while(i < j && arr[i] <= pivot){
      ++i;
    }//当i=j后 i还向前多移动一位
    if(i < j){
      swap(&arr[i], &arr[j]);//&符号取地址
    }
  }
  swap(&arr[left], &arr[i]);
  return i;//返回下标
}


static void quick_sort(int arr[], int left, int right)
{
  int pivot_pos;

  if(left < right){
    pivot_pos = partition(arr, left, right);//交换后的下标
    quick_sort(arr, left, pivot_pos - 1);//前面的i多向前跑了一位
    quick_sort(arr, pivot_pos + 1, right);//原本是从pivot_pos开始,但是上面-1了,下面就要+1
  }
}

int main(){
  int arr[] = {9, 8, 9, 10, 4, 1, 6, 7};
  int L = 0;
  int R = 7;
  int i;
  quick_sort(arr, L, R);
  for(i = 0; i <= R; i++){
    std::cout << arr[i] << '\n';
  }
}

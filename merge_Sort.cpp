#include<iostream>
using namespace std;
//归并排序
void merge(int arr[], int L, int M, int R)
{
  int LEFT_SIZE = M - L + 1;
  int RIGHT_SIZE = R - M;
  int left[LEFT_SIZE];//定义左边的数组
  int right[RIGHT_SIZE];//定义右边的数组
  int i, j, k;

  //1.填充左边的数组
  for(i = L; i <= M; i++){
    left[i-L] = arr[i];
  }

  //2.填充右边的数组
  for(i = M + 1; i <= R; i++){
    right[i - M -1] = arr[i];
  }

  //测试
  // for(int i = 0; i < LEFT_SIZE; i++){
  //   std::cout << left[i] << '\n';
  // }

  //将两个数组合并
  i = 0; j = 0; k = L;
  while (i < LEFT_SIZE && j < RIGHT_SIZE) {//三个指针i,j是两个待合并的数组，k是合并的
    if(left[i] < right[j]){
      arr[k] = left[i];
      i++;
      k++;
    }else{
      arr[k] = right[j];
      j++;
      k++;
    }
  }
  //如果是左边的数组还有剩余,直接将左边的全部插入
  while(i < LEFT_SIZE){
    arr[k] = left[i];
    i++;
    k++;
  }
  //如果是右边的数组还有剩余,直接将右边的全部插入
  while(j < RIGHT_SIZE){
    arr[k] = right[j];
    j++;
    k++;
  }
}

//使用分治法
void mergeSort(int arr[], int L, int R){
  if(L == R){
    return ;
  }else{
    int M = (L + R) / 2;
    mergeSort(arr, L, M);
    mergeSort(arr, M + 1, R);
    merge(arr, L, M, R);
  }
}



int main(){
  int arr[] = {9, 8, 9, 10, 4, 1, 6, 7};
  int L = 0;
  int R = 7;
  int i;
  mergeSort(arr, L, R);
  for(i = 0; i <= R; i++){
    std::cout << arr[i] << '\n';
  }
}

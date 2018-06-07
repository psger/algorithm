#include<iostream>
using namespace std;

void Shell_sort(int *arr, int n)
{
  int i, j, gap;
  int tmp;
  for(gap = n/2; gap > 0; gap /= 2){
    for(i = gap; i < n; ++i){
      tmp = arr[i];
      for(j = i - gap; j >= 0 && arr[j] > tmp; j -= gap){
        arr[j+gap] = arr[j];
      }
      arr[j+gap] = tmp;
    }
  }
}

int main()
{
     int data[]={5,1,19,22,3,1,23,6};    //输入待排序数组
     Shell_sort(data,8);
     for(int i = 0; i < 8; i++)
        cout<<data[i]<<" ";
    cout<<"\n";
		return 0;
}

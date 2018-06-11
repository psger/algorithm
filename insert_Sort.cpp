#include<iostream>
using namespace std;
//插入排序
void InsertSort(int array[], int n)
{
  int i, j;
  for (i = 1; i < n; i++){
    int temp = array[i];
      for (j = i - 1; j >= 0 && array[j] > temp; j--){
        array[j + 1] = array[j];

    }
    cout<<"*"<<j<<" ";
    array[j+1] = temp;
  }
}


int main()
{
     int data[]={5,1,19,22,3,1,23,6};    //输入待排序数组
     InsertSort(data,8);
     for(int i = 0; i < 8; i++)
        cout<<data[i]<<" ";
    cout<<"\n";
		return 0;
}

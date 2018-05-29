#include<iostream>
using namespace std;

void selectionSort(int *pData, int n){
  int minIndex, temp;
  for(int i=0; i<n-1;i++){
    minIndex = i;
    for(int j=i+1; j<n; j++){
      if(pData[j]<pData[minIndex]){
        minIndex = j;
      }
    }
    temp = pData[i];
    pData[i] = pData[minIndex];
    pData[minIndex] = temp;
  }
}


int main()
{
     int data[]={5,1,19,22,3,1,23,6};    //输入待排序数组
     selectionSort(data,8);              //冒泡排序法
    for(int i=0;i<8;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
		return 0;
}

#include<iostream>
using namespace std;

// void selectionSort(int array[], int n){
//   for(int i = 0; i<n-1; i++){
//     int min = array[i]; int tmp;
//     for(int j = i+1; j<n; j++){
//       if(array[j]<min){
//         tmp = array[j];
//         array[j] = min;
//         min = tmp;
//       }
//     }
//     array[i] = min;
//   }
// }

void selectionSort2(int array[], int n){
  int i, j, min, max;
  for( i = 0; i<n/2; i++){
    int min = max = i;
    for( j = i + 1; j<n-i; j++){
      if(array[j]<array[min]){
        min = j;
      }
      if(array[j]>array[max]){
        max = j;
      }
    }

    int mintmp = array[min];
    int maxtmp = array[max];

    array[min] = array[i];
    array[max] = array[n-i-1];

    array[i] = mintmp;
    array[n-i-1] = maxtmp;
  }
}

int main()
{
     int data[]={5,1,19,22,3,1,23,6};    //输入待排序数组
     selectionSort2(data,8);
    for(int i=0;i<8;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
		return 0;
}

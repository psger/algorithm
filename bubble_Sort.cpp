#include<iostream>
using namespace std;

void BulleSort(int* pData, int Count)
{
    // int iTemp=0;
    // for(int i=1;i<Count;i++)     //进行Count次排序，Count是排序的数的个数
    // {
    //     for(int j=Count-1;j>=i;j--)  //对该轮待排序的数进行排序
    //     {
    //         if(pData[j]<pData[j-1])  //将大数放在前，小数放在后
    //         {
    //             iTemp=pData[j-1];
    //             pData[j-1]=pData[j];
    //             pData[j]=iTemp;
    //         }
    //     }
    // }

		int temp = 0;
		for(int i = 0; i<Count-1; i++){//应该排序的次数
			for(int j=0; j<Count-i-1; j++){//第几次排序后就应该有几个数被排好,即不再需要比较,-i//j=1;j<Count-i;j++
				if(pData[j]>pData[j+1]){//if(pData[j]<pData[j-1])
					temp = pData[j];
					pData[j] = pData[j+1];
					pData[j+1] = temp;
				}
			}
		}
}


//对冒泡排序进行优化
void BulleSort_Optimize(int* pData, int Count){
	int i ,j ;
	bool flag = true;
	for(i=0;i<arrayLength-1&&flag;++i)
	{
			flag = false;
			for(j= 1;j<arrayLength-i;++j)
					if(array[j]<array[j-1])
					{
							Swap(array[j],array[j-1]);
							flag = true;  //有交换，表明当前序列尚未有序，标志为ture
					}
	}
}


int main()
{
     int data[]={5,1,19,22,3,1,23,6};    //输入待排序数组
     BulleSort(data,8);              //冒泡排序法
    for(int i=0;i<8;i++)
        cout<<data[i]<<" ";
    cout<<"\n";
		return 0;
}

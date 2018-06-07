#include<iostream>
using namespace std;

void Shell_sort(int a[],size_t n)
{
    int i,j,k,group;
    for (group = n/2; group > 0; group /= 2)//增量序列为n/2,n/4....直到1
    {
        for (i = 0; i < group; ++i)
        {
            for (j = i+group; j < n; j += group)
            {
                //对每个分组进行插入排序
                if (a[j - group] > a[j])
                {  
                    int temp = a[j];
                    k = j - group;
                    while (k>=0 && a[k]>temp)
                    {
                        a[k+group] = a[k];
                        k -= group;
                    }
                    a[k] = temp;
                }
            }
        }
    }
}

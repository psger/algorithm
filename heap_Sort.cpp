#include<iostream>
using namespace std;
//堆排序
//堆赛选函数
//已知H[start-end]中除了start之外均满足堆的定义
//本函数进行调整，使H[start-end]成为一个大顶堆
typedef int ElemType;
void HeapAdjust(ElemType H[], int start, int end) {
    ElemType temp = H[start];
    for (int i = 2 * start + 1; i <= end; i *= 2) {
        //因为根节点的序号为0 而不是1  所以i结点左孩子和右孩子分别为2i+1和2i+2
        if (i < end && H[i] < H[i + 1]) {
            //左右孩子进行比较
            ++i;//i为较大记录的下标
        }
        if (temp > H[i]) {
            //左右孩子中获胜者与父亲的比较
            break;
        }
        //将孩子结点上位，则以孩子结点的位置进行下一轮的赛选
        H[start] = H[i];
        start = i;
    }
    H[start] = temp;//插入最开始不和谐的元素
}

void HeapSort(ElemType A[], int n) {
    //先建立大顶堆
    for (int i = n/2; i >= 0; --i) {
        HeapAdjust(A, i, n);
    }
    //进行排序
    for (int i = n - 1; i > 0; --i) {
        //最后一个元素和第一个元素进行交换 就是将大的元素放到数组后面然后继续调整为最大堆 
        ElemType temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        //然后将剩下的无序元素继续调整为大顶堆
        HeapAdjust(A, 0, i - 1);
    }
}

int main() {
    int a[] = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
    int len = sizeof(a)/sizeof(int);
    HeapSort(a, len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

//1.冒泡排序
//两两比较放到最后，每一趟都会选出一个最大或者最小
//O(n^2)
void bubbleSort(int array[], int n)
{
  for(int i = 0; i < n - 1; i++){//i是比较的次数，一共要比较n-1次,这里的i从0开始，所以要<n-1
    for(int j = 0; j < n - 1 - i; j++){
      if(array[j] > array[j + 1])
      swap(array[j], array[j + 1]);
    }
  }
}
//冒泡优化 设置标志变量
function bubbleSort2(int array[], int n)
{
  int i, j, change = 0;

  for(i = 0; i < n - 1 && change != 0; i++){//如果没有交换(change=0)就终止循环
   change = 0;//在n-1次比较中，只要有一次没有交换就有序了
    for(j = 0; j < n - 1 - i; j++){
      if(array[j] > array[j + 1]){
        swap(array[j] > array[j++]);
        change = 1;//表示有交换
      }
    }
  }
}
********************************************************************************
//2.选择排序
//从后面的选出最小的放到前面
//O(n^2)
void selectionSort(int array[], int n)
{
  int minIndex = 0;

  for(int i = 0; i < n - 1; i++){
    minIndex = i;
    for(int j = i + 1; j < n; j++){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }
    }
    swap(array[minIndex], array[i]);
  }
}
********************************************************************************
//插入排序
//把后面的按大小插入到前面
//O(n^2)
void insertSort(int array[], int n)
{
  int i, j, tmp;

  for(int i = 1; i < n; i++){
    tmp = array[i];
    for(int j = i - 1; j >= 0; j--){
      if(array[j] > tmp)
      {
        array[j + 1] = array[j];
      }else{
        break;
      }
    }
    array[j + 1] = tmp;// 到-1时终止循环，所以要加一
  }
}

//插入排序
void insertSort(int array[], int n){
  for(int i = 0; i < n; i++){
    int tmp = array[i];
    for(int j = i -1; j >= 0 && array[j] > tmp; j--){
      array[j + 1] = array[j];//将大的数向前移动
    }
    array[j + 1] = tmp;//将小的数插入到空位中
  }
}

********************************************************************************
//希尔排序
//基于插入排序，平均O(n^1.3)
void shellSort(int *array, int n){
  int i, j, gap;
  for(gap = n / 2; gap > 0; gap /= 2){
    for(int i = gap; i < n; i++){
      int tmp = array[i];
      for(int j = i + gap; j >= 0 && array[j] > tmp; j -= gap){
        array[j + gap] = array[j];
      }
      array[j + gap] = tmp;
    }
  }
}

********************************************************************************
//归并排序
//用到分治法的思想，将数组不断的分下去，分到最后只剩下一个元素就是有序的了，再来合并成有序的数组
//分治法的基本思想是：将原问题分解为若干个规模更小但结构与原问题相似的子问题。递归地解这些子问题，
//然后将这些子问题的解组合为原问题的解。
//O(nlogn)
void merge(int arr[], int L, int M, int R){
  int LEFT_SIZE = M - L + 1;
  int RIGHT_SIZE = R - M;
  int left[LEFT_SIZE];
  int right[RIGHT_SIZE];

  for(int i = L; i <= M; i++){//拆分的时候M是包含在右边的
    left[i - L] = arr[i];
  }

  for(int i = M + 1; i <= R; i++){
    right[i - M - 1] = arr[i];
  }

  //将两个数组合并为一个有序的数组
  i = 0; j = 0; k = 0;
  while(i < LEFT_SIZE && j < RIGHT_SIZE){
    if(left[i] < right[j]){
      arr[k] = left[i];
      i++;
      k++
    }else{
      arr[k] = right[j];
      j++;
      k++;
    }
  }

  while(i < LEFT_SIZE){
    arr[k] = left[i];
    i++;
    k++;
  }

  while(j < RIGHT_SIZE){
    arr[k] = right[j];
    i++;
    k++;
  }
}

//分治法
void merge_sort(int arr[], int L, int R){
  if(L == R)//如果只有一个元素
  return;

  int M = (L + R) / 2;//为什么要加L,不直接R/2 ? 右边的L是从M+1开始的，并不是0
  merge_sort(arr, L, M);//这个时候M是包含在左边的
  merge_sort(arr, M + 1, R);
  merge(arr, L, M, R);//注意中点边界M
}
********************************************************************************

//快速排序

//选一个基数，分成两个数组
int partition(int arr[], int left, int right)
{
  int i = left;//定义左右边界
  int j = right;

  int pivot = arr[left];//将左边的选为基数

  while(i < j){；
    while(i < j && arr[i] < pivot){//从左到右的数小于基数 i就向右移
      i++;
    }

    while(j > i && arr[j] > pivot){////从右到左的数小于基数 i就向左移
      j--;
    }
    //不符合条件就交换
    swap(arr[i], arr[j]);
  }
  //循环完了之后交换基数于i的位置
  swap(arr[i], pivot);
  return i;//返回i的下标
}

//分治法，递归去分解每一个数组
void quick_sort(int arr[], int left, int right)
{
    int pivot_pos;

    if(left < right){
      pivot_pos = partition(arr, left, right);
      quick_sort(arr, left, pivot_pos);
      quick_sort(arr, pivot_pos + 1, right);
    }
}

********************************************************************************
//堆排序
//先建立大(小)顶堆，然后将顶元素与尾元素交换，重新构建大(小)顶堆
void HeapAdjust(int arr[], int start, int end){
  int tmp = arr[start];

  for(int i = 2 * start + 1; i <= end; i++){
    if(i < end && arr[i] < arr[i + 1]){
      i++;
    }

    if(tmp > arr[i])
    {
      break;
    }

    arr[start] = arr[i];
    start = i;
  }

  arr[start] = tmp;
}

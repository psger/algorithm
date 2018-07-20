//1.冒泡排序
void bubbleSort(int array[], int n)
{
  for(int i = 0; i < n - 1; i++){
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

  for(i = 0; i < n - 1 && change != 0; i++){
   change = 0;//这里置0是为了每一次比较，只要有一次没有交换就有序了
    for(j = 0; j < n - 1 - i; j++){
      if(array[j] > array[j + 1]){
        swap(array[j] > array[j++]);
        change = 1;
      }
    }
  }
}

//2.选择排序
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

//插入排序
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


//希尔排序
void shellSort(int *array, int n){
  int i, j, gap;
  for(gap = n / 2; gap > 0; gap /= 2){
    for(int i = 0; i < n; i++){
      int tmp = array[i];
      for(int j = i + gap; j >= 0 && array[j] > tmp; j--){
        array[j + gap] = array[j];
      }
      array[j + gap] = tmp;
    }
  }
}

*******************************************************************
//归并排序
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

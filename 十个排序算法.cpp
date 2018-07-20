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

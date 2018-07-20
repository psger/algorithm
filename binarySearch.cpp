include <iostream>

using namespace std;
//边界为【L, R】
int binarySearch(int array[], int n, int target){
    int l = 0;
    int r = n - 1;
    int middle = (r - l) / 2 + l;
    while(l <= r){
        if(target > array[middle] )
            l = middle + 1;
        else if(target < array[middle])
            r = middle - 1;
        else return array[middle];
    }
    return -1;
}



//边界为[L, R)
int binarySearch2(int array[], int n, int target){
    int l = 0;
    int r = n;
    int middle = l + (r - l) >> 1
        while(l < r){
            if(target > array[middle])
                l = middle + 1;
            else if(target < array[middle])
                r = middle;
            else return array[middle];
        }
    return -1;
}

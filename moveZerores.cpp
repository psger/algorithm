#include <iostream>
#include <vector>


using namespace std;

class Solution{
    public:
        void moveZeroes(vector <int>& nums){
            vector<int> nonZeroElements;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i])
                nonZeroElements.push_back(nums[i]);
                }
            for(int i = 0; i < nums.size(); i++){
                nums[i] = nonZeroElements[i];
            }

            for(int i = nonZeroElements.size(); i < nums.size(); i++){
                nums[i] = 0;
            }

        }
    }
}


//不使用额外的空间
void moveZeroes(vector<int>& nums){
    int k = 0;
    int i = 0;
        for(; i < nums.size(); i++){
            if(nums[i])
                if(i != k)//如果全部是非0元素，那么就不需要自身和自身交换了
                swap(nums[k++], nums[i]);
            else
                k++;
        }
}

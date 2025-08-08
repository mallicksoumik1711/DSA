// https://leetcode.com/problems/move-zeroes/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]
*/

void moveZeros(vector<int>& nums){
    if(nums.size() <= 1){
        return;
    }
    int i=0, j=i+1;
    while(j < nums.size()){
        if(nums[i] == 0 && nums[j] != 0){
            // swap i++, j++
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i += 1;
            j += 1;
        }
        if(nums[i] == 0 && nums[j] == 0){
            j += 1;
        }
        if(nums[i] != 0 && nums[j] != 0){
            i += 1;
            j += 1;
        }
        if(nums[i] != 0 && nums[j] == 0){
            i += 1;
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeros(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] <<" ";
    }
}
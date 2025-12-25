// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=problem-list-v2&envId=two-pointers

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:                                   

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
*/

int duplicateNumber_Array_modification(vector<int> &nums){
    for(int i=0; i<nums.size(); i++){
        int idx = abs(nums[i]);
        if(nums[idx] > 0){
            nums[idx] = -nums[idx];
        }
        else{
            return idx;
        }
    }
    return 0;
}

void returnStoredIndex(vector<int> &arr, int k, vector<int> nums){
    //return stored indexes
    for(int i=0; i<arr.size(); i++){
        if(arr[i] && arr[i]>nums[i]){
            //return expected result
        }
    }
}

int tortoise_and_hare_cycle_detection_algo(vector<int>& nums){
    int slow = nums[0];
    int fast = nums[0];

    slow = nums[slow];
    fast = nums[nums[fast]];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    slow = nums[0];

    while(slow != fast){    
        fast = nums[fast];
    }
    return slow; //fast bhi work krega
}

int main(){
    vector<int> nums = {1,3,4,2,2};
    // int ans = duplicateNumber_Array_modification(nums);
    int ans = tortoise_and_hare_cycle_detection_algo(nums);
    cout << ans;
}

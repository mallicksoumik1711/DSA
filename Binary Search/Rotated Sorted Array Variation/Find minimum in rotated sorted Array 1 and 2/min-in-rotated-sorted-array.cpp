// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1732465141/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/

int minimumInRotatedSorted(vector<int> &nums){
    int l=0, h=nums.size()-1;
    int mini = INT_MAX;
    while(l <= h){
        int mid = (l+h)/2;
        if(nums[l] <= nums[mid]){
            mini = min(mini, nums[l]);
            l = mid+1;
        }
        else{
            mini = min(mini, nums[mid]);
            h = mid-1;
        }
    }
    return mini;
}

int main(){
    vector<int> nums = {5,1,2,3,4};
    int ans = minimumInRotatedSorted(nums);
    cout << ans;
    return 0;
}
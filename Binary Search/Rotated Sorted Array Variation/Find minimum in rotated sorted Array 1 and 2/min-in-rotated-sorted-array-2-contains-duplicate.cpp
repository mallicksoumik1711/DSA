// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0 
*/

int minimumInRotatedSorted_2(vector<int> &nums){
    int l=0, h=nums.size()-1;
    int mini = INT_MAX;
    while(l <= h){
        int mid = (l+h)/2;
        if(l != mid && nums[mid] == nums[l]){
            l += 1;
            continue;
        }
        if(mid != h && nums[mid] == nums[h]){
            h -= 1;
            continue;
        }
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
    vector<int> nums = {1,0,1,1,1};
    int ans = minimumInRotatedSorted_2(nums);
    cout << ans;
    return 0;
}
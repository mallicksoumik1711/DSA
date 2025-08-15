// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1732174495/
#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

int rotatedSortedArray(vector<int> &nums, int target){
    int l=0, h=nums.size()-1;
    while(l <= h){
        int mid = (l+h)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[l] <= nums[mid]){
            if(target >= nums[l] && target <= nums[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
           if(target >= nums[l] && target <= nums[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            } 
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int ans = rotatedSortedArray(nums, target);
    cout << ans;
}
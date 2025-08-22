// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

int leftIndex(vector<int> &nums, int target){ 
    int l=0, h=nums.size()-1;
    int first = -1;
    while(l <= h){
       int mid = (l+h)/2;
       if(nums[mid] == target){
        first = mid;
        h = mid-1; //since left index will be present at left side only
       } 
       else if(nums[mid] < target){
        l = mid+1;
       }
       else{
        h = mid-1;
       }
    }
    return first;
}

int rightIndex(vector<int> &nums, int target){
    int l=0, h=nums.size()-1;
    int second = -1;
    while(l <= h){
       int mid = (l+h)/2;
       if(nums[mid] == target){
        second = mid;
        l = mid+1; //since right index will be present at right side only
       } 
       else if(nums[mid] < target){
        l = mid+1;
       }
       else{
        h = mid-1;
       }
    }
    return second;
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    cout << leftIndex(nums, target) << " " << rightIndex(nums, target) <<endl;
    return 0;
}

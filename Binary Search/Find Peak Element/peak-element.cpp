// https://leetcode.com/problems/find-peak-element/description/

#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &nums){
    int l=1, h=nums.size()-2;
    if(nums.size()==1){
        return 0;
    }
    if(nums[0] > nums[1]){
        return 0;
    }
    if(nums[nums.size()-1] > nums[nums.size()-2]){
        return nums.size()-1;
    }
    while(l <= h){
        int mid = (l+h)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return mid;                                                     //returning INDEX not VALUE
        }
        else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,2,3,1};
    int ans = peakElement(nums);
    cout << ans;
    return 0;
}

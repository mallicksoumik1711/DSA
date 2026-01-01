// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &nums){
    int l=0, h=nums.size()-1;
    if(nums.size() <= 1){
        return nums[0];
    }
    if(nums[0] != nums[1]){
        return nums[0];
    }
    if(nums[nums.size()-1] != nums[nums.size()-2]){
        return nums[nums.size()-1];
    }
    while(l <= h){
        int mid = (l+h)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }
        else if(mid%2 == 0){
            if(nums[mid] == nums[mid-1]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
            if(nums[mid] == nums[mid-1]){
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
    vector<int> nums = {1,1,2,3,3,4,4,7,7,8,8};
    int ans = singleElement(nums);
    cout << ans;
    return 0;
}

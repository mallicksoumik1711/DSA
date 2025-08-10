// https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include<bits/stdc++.h>
using namespace std;

// we have to count number of subarrays... so length of each subarray is required which satisfies the condition

/** CONDITION - 
 * To find exact number of subarrays we've to opt a solution.
 * given when doubt which pointer to move (left, right) opt this method.
         
 * Exact (k) = [subarrays <= (k)] - [subarrays < (k)]
**/



int binarySubarraySum(vector<int> &nums, int target){
    int sum = 0;
    int ans = 0;
    int l=0, r=0;
    while(r < nums.size()){
        sum += nums[r];
        while(sum > target){
            sum -= nums[l];
            l += 1;
        }
        ans += r-l+1;
        r += 1;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,0,1,0,1};
    int target = 2;
    int ans = binarySubarraySum(nums, target) - binarySubarraySum(nums, target-1);
    cout << ans;
    return 0;
}

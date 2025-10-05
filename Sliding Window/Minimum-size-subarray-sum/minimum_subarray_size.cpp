// https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
                                   
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

int minimumSizeSubarray(vector<int> &nums, int target){
    int mini = INT_MAX;
    int sum = 0;
    int l=0, r=0;
    while(r < nums.size()){
        sum += nums[r];
        while(sum >= target){
            mini = min(mini, r-l+1);
            sum -= nums[l];
            l += 1;
        }
        r += 1;
    }
    return mini == INT_MAX ? 0 : mini;
}

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int ans = minimumSizeSubarray(nums, target);
    cout << ans;
    return 0;
}

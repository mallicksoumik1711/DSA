// https://leetcode.com/problems/maximum-erasure-value/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
*/

int maxiSubArrayWithUniques(vector<int> &nums){
    set<int> st;
    int l=0, r=0;
    int sum = 0, maxi = -1;
    while(r < nums.size()){
        if(st.find(nums[r]) != st.end()){
            while(st.find(nums[r]) != st.end()){
                st.erase(nums[l]);
                sum -= nums[l];
                l += 1;
            }
        }
            st.insert(nums[r]);
            sum += nums[r];
            maxi = max(maxi, sum);
        r += 1;
    }
    return maxi;
}

int main(){
    vector<int> nums = {4,2,4,5,6};
    int ans = maxiSubArrayWithUniques(nums);
    cout << ans;
    return 0;
}
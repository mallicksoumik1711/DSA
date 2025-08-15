// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
*/

int countSubarrays(vector<int> &nums, int n){
    unordered_map<int, int> mpp;
    int l=0, r=0;
    int count = 0;
    while(r < nums.size()){
        mpp[nums[r]] += 1;
        while(mpp.size() > n){
            mpp[nums[l]] -= 1;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l += 1;
        }
        count += r-l+1;
        r += 1;
    }
    return count;
}

int main(){
    vector<int> nums = {1,3,1,2,2};
    set<int> st;
    for(int i=0; i<nums.size(); i++){
        st.insert(nums[i]);
    }
    int n = st.size();

    int subarray_lessThan_EqualTo_Complete_Subarrays = countSubarrays(nums, n);
    int subarray_EqualTo_Complete_Subarrays = countSubarrays(nums, n-1);
    int ans = subarray_lessThan_EqualTo_Complete_Subarrays - subarray_EqualTo_Complete_Subarrays;
    cout << ans;
    return 0;
}
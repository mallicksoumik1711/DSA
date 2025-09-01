// https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=problem-list-v2&envId=sliding-window

/*
Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3    
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

#include<bits/stdc++.h>
using namespace std;

int k_unique_subarray(vector<int> &nums, int k){
    unordered_map<int, int> mpp;
    int count = 0;
    int l=0, r=0;
    if(k < 0){
        return 0; //condition if k=0 then k-1 = -1, thus require -> 0;
    }
    while(r < nums.size()){
        mpp[nums[r]] += 1;
        while(mpp.size() > k){
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
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    int ans = k_unique_subarray(nums, k) - k_unique_subarray(nums, k-1);
    cout << ans;
    return 0;
}

// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

/* 
Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2 this tc will prove whether to move right or left pointer
Output: 16
*/

int countSubarrays(vector<int> &nums, int k){
    int oddNum = 0;
    int ans = 0;
    int l=0, r=0;

    if(k < 0){
        return 0;
    }
    // if k = 0 then k-1 = -1 thus to keep this safe.
    
    while(r < nums.size()){
        if(nums[r]%2 != 0){
            oddNum += 1;
            //oddNum *= 4; remove later
        }
        while(oddNum > k){
            if(nums[l]%2 != 0){
                oddNum -= 1;
            }
            l += 1;
        }
        ans += r-l+1; //since it is asking number of subarrays
        r += 1;
    }
    return ans;
}

int main(){
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k = 2;
    int ans = countSubarrays(nums, k) - countSubarrays(nums, k-1);
    cout << ans;
    return 0;
}

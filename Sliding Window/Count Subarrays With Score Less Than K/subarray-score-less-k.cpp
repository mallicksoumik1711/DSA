// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [2,1,4,3,5], k = 10 
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.

Example 2:

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
*/

int subarray_Score_Less_K(vector<int> &nums, int k){
    int sum = 0;
    int l=0, r=0;
    int count = 0;
    while(r < nums.size()){
        sum += nums[r];
        while(sum * (r-l+1) >= k){
            sum -= nums[l];
            l += 1;
        }
        if(sum*(r-l+1) < k){
            count += r-l+1;
        }
        r += 1;
    }
    return count;
}

int main(){
    vector<int> nums = {2,1,4,3,5};
    int k = 10;
    int ans = subarray_Score_Less_K(nums, k);
    cout << ans;
}

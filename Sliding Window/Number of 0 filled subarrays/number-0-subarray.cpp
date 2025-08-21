// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/?envType=daily-question&envId=2025-08-19

#include <bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation:
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
Example 2:

Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
Example 3:

Input: nums = [2,10,2019]
Output: 0
Explanation: There is no subarray filled with 0. Therefore, we return 0.
*/

long long zerosSubarray(vector<int> &nums)
{
    int l = 0, r = 0;
    long long sum = 0;
    long long ans = 0;
    while (r < nums.size())
    {
        if (nums[r] != 0)
        {
            ans += sum;
            sum = 0;
            r += 1;
            l = r;
        }
        else
        {
            sum += r - l + 1;
            r += 1;
        }
    }
    ans += sum;
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    long long ans = zerosSubarray(nums);
    cout << ans;
    return 0;
}
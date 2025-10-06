// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3                  
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
*/

int subarrayWithAvg(vector<int> &nums, int k, int threshold){
    int l=0, r=0;
    int sum=0, avg=0, result=0;
    while(r < nums.size()){
        sum += nums[r];
        if(r-l+1 == k){
            avg = sum/k;
            if(avg >= threshold){
                result += 1;
            }
            sum -= nums[l];
            l += 1;
        }
        r += 1;
    }
    return result;
}

int main(){
    vector<int> nums = {2,2,2,2,5,5,5,8};
    int k = 3;
    int threshold = 4;
    int ans = subarrayWithAvg(nums, k, threshold);
    cout << ans;
    return 0;
}

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

bool isPossible(vector<int> &nums, int mid, int threshold){
    long long sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += ceil((double)nums[i]/(double)mid);
        if(sum > threshold){
            return false;
        }
    }
    return true;
}
int smallestDivisior(vector<int> &nums, int threshold){
    int l = 1;
    int h = *max_element(nums.begin(), nums.end());
    if(nums.size() == threshold) return h;
    int ans = 0;
    while(l <= h){
        int mid = (l+h)/2;
        bool smallest = isPossible(nums, mid, threshold);
        if(smallest){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int ans = smallestDivisior(nums, threshold);
    cout << ans;
    return 0;
}
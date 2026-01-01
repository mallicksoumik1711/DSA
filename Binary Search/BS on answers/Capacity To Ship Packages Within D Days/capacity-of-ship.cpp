// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
     
#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8                
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/
int sumOfAllweights(vector<int> &nums){
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }
    return sum;
}
bool isPossible(vector<int> &nums, int mid, int days){
    long long sum = 0;
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(sum > mid){
            count += 1;
            sum = nums[i];
        }
    }
    if(count+1 <= days){
        return true;
    }
    return false;
}
int shipCapacity(vector<int> &nums, int days){
    // Its important to know the range of answers
    // lowest range would be maximum number ans highest will be sum of all digits
    int l = *min_element(nums.begin(), nums.end());
    int h = sumOfAllweights(nums);
    int ans = 0;
    while(l <= h){
        int mid = (l+h)/2;
        int capacity = isPossible(nums, mid, days);
        if(capacity){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
}
int main(){
    vector<int> nums = {3,2,2,4,1,4};
    int days = 3;
    int ans = shipCapacity(nums, days);
    cout << ans;
    return 0;
}

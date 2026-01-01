// https://leetcode.com/problems/koko-eating-bananas/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:  

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/

long long helperFunction(vector<int> &nums, int mid, int hours){
    long long sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += ceil((double)nums[i] / (double)mid);
        if(sum > hours){
            return sum;
        }
    }
    return sum;
}

int kokoEatingBanana(vector<int> &nums, int hours){
    int l = 1;                                      //cannot take l as min element because of this tc - piles = [312884470], h = 312884469
    int h = *max_element(nums.begin(), nums.end());
    int ans = 0;
    while(l <= h){
        int mid = (l+h)/2;
        long long speed = helperFunction(nums, mid, hours);
        if(speed <= hours){
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
    vector<int> nums = {30,11,23,4,20};
    int hours = 5;
    int ans = kokoEatingBanana(nums, hours);
    cout << ans;
    return 0;
}

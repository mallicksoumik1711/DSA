// https://leetcode.com/problems/max-consecutive-ones-iii/

#include<bits/stdc++.h>
using namespace std;

int maxConsecutive(vector<int> &nums, int k){
    int l=0, r=0;
    int maxi = INT_MIN;
    int zeros = 0;

    while(r < nums.size()){
        if(nums[r] == 0){
            zeros += 1;
        }
        while(zeros > k){
            if(nums[l] == 0){      
                zeros -= 1;
            }
            l += 1;
        }
        if(zeros <= k){
            maxi = max(maxi, r-l+1);
        }
        r += 1;
    }
    return maxi;
}

int maxConsecutiveOnesOptimal(vector<int> &nums, int k){
    int l=0, r=0;
    int maxi = INT_MIN;
    int zeros = 0;

    while(r < nums.size()){
        if(nums[r] == 0){
            zeros += 1;
        }
        if(zeros > k){
            if(nums[l] == 0){
                zeros -= 1;
            }
            l += 1;
        }
        if(zeros <= k){
            maxi = max(maxi, r-l+1);
        }
        r += 1;
    }
    return maxi;
}

int main(){
    // Give different input here 
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;

    int ans = maxConsecutive(nums, k); //better not optimal
    int ans_optimal = maxConsecutiveOnesOptimal(nums, k); //optimal one
    cout << ans;
    return 0;
}

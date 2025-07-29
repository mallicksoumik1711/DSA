// https://leetcode.com/problems/fruit-into-baskets/description/

#include<bits/stdc++.h>
using namespace std;

int fruitBasket(vector<int> &nums){
    unordered_map<int, int> mpp;
    int maxi = INT_MIN;
    int l=0, r=0;
    while(r < nums.size()){
        mpp[nums[r]] += 1;
        while(mpp.size() > 2){
            mpp[nums[l]] -= 1;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l += 1;
        }
        if(mpp.size() <= 2){
            maxi = max(maxi, r-l+1);
        }
        r += 1;
    }
    return maxi;
}

int fruitBasketOptimal(vector<int> &nums){
    unordered_map<int, int> mpp;
    int maxi = INT_MIN;
    int l=0, r=0;
    while(r < nums.size()){
        mpp[nums[r]] += 1;
        if(mpp.size() > 2){
            mpp[nums[l]] -= 1;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l += 1;
        }
        if(mpp.size() <= 2){
            maxi = max(maxi, r-l+1);
        }
        r += 1;
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,3,2,2};
    int ans = fruitBasket(nums);
    int ans_optimal = fruitBasketOptimal(nums);
    cout << ans_optimal;
    return 0;
}

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> findSum(vector<int> &nums, int k){
        int sum = 0;
        int l = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
            l = i;
        }
        return {sum, l};
    }
    int maxScore(vector<int>& cardPoints, int k) {
        pair<int, int> store = findSum(cardPoints, k);
        int sum = store.first;
        int l = store.second;
        int r = cardPoints.size()-1;
        int maxi = sum;
        while(l >= 0){
            sum -= cardPoints[l];
            sum += cardPoints[r];
            maxi = max(maxi, sum);
            l -= 1;
            r -= 1;
        }
        return maxi;
    }

int maxPoints(vector<int> &nums, int k){
    int lSum = 0;
    int rSum = 0;

    for(int i=0; i<k; i++){
        lSum += nums[i];
    }
    int maxi = lSum;

    int l = k-1, r = nums.size()-1;
    while(l >= 0){
        lSum -= nums[l];
        l -= 1;
        rSum += nums[r];
        r -= 1;
        maxi = max(maxi, lSum+rSum);
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,1};
    int k = 3;
    int ans = maxPoints(nums, k);
    cout << ans;
    return 0;
}

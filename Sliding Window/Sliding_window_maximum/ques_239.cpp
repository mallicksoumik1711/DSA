// https://leetcode.com/problems/sliding-window-maximum/description

#include<bits/stdc++.h>
using namespace std;

vector<int> maxNumber(vector<int> &nums, int k){
    vector<int> ans;
    int maxi = INT_MIN;
    list<int> li;
    int l=0, r=0;
    while(r < nums.size()){
        maxi = max(maxi, nums[r]);
        while(!li.empty() && li.back()<nums[r]){
            li.pop_back();
        }
        li.push_back(nums[r]);
        if(r-l+1 < k){
            r += 1;
        }
        if(r-l+1 == k){
            ans.push_back(li.front());
            if(li.front() == nums[l]){
                li.pop_front();
            }
            l += 1;
            r += 1;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxNumber(nums, k);
    // return ans
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxi = -1;
        int l=0, r=0;
        if(s.size() == 0){
            return 0;
        }
        while(r < s.size()){
            mpp[s[r]] += 1;
            if(r-l+1 == mpp.size()){
                maxi = max(maxi, r-l+1);
                r += 1;
            }
            else{
                mpp[s[l]] -= 1;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l += 1;
                r += 1;
            }
        }
        return maxi;
    }

int longestSubstr(string &s){
    int maxi = INT_MIN;
    unordered_map<char, int> mpp;
    int l=0, r=0;
    while(r < s.size()){
        mpp[s[r]] += 1;
        if(mpp.size() != r-l+1){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
            r += 1;
        }
        if(mpp.size() == r-l+1){
            maxi = max(maxi, r-l+1);
            r += 1;
        }
    }
    return maxi==INT_MIN ? 0 : maxi; //necessary for tc when there will be no  string available
}

int main(){
    string s = "pwwkew"; //here input different inputs
    int ans = longestSubstr(s);
    cout << ans;
    return 0;
}

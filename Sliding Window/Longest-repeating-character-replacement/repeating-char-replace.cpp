// https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include<bits/stdc++.h>
using namespace std;

int longestRepeatingChar(string &s, int k){
    unordered_map<char, int> mpp;
    int maxfreq = -1;
    int maxi = -1;
    int l=0, r=0;
    while(r < s.size()){
        mpp[s[r]] += 1;
        maxfreq = max(maxfreq, mpp[s[r]]);
        if(r-l+1 - maxfreq <= k){
            maxi = max(maxi, r-l+1);
        }
        while(r-l+1 - maxfreq > k){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
        }
        r += 1;
    }
    return maxi;
}

int main(){
    string s = "AABABBA";
    int k = 2;
    int ans = longestRepeatingChar(s, k);
    cout << ans;
    return 0;
}

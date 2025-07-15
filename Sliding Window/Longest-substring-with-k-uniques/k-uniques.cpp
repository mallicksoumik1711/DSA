// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k){
    int maxi = -1;
    unordered_map<char, int> mpp;
    int l=0, r=0;

    while(r < s.size()){
        mpp[s[r]] += 1;
        while(mpp.size() > k){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
        }
        maxi = max(maxi, r-l+1);
        r += 1;
    }

    return mpp.size() == k ? maxi : -1;
}

int main(){
    string s = "aabacbebebe";
    int k = 3;
    int ans = longestSubstring(s, k);
    cout << ans;
    return 0;
}
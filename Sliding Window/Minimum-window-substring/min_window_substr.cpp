// https://leetcode.com/problems/minimum-window-substring/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

string mininSubstring(string s, string t){
    unordered_map<char, int> mpp;
    for(int i=0; i<t.size(); i++){
        mpp[t[i]] += 1;
    }
    int start_idx = -1;
    int mini = INT_MAX;
    int count = mpp.size();
    int l=0, r=0;
    while(r < s.size()){
        if(mpp.find(s[r]) != mpp.end()){
            mpp[s[r]] -= 1;
            if(mpp[s[r]] == 0){
                count -= 1;
            }
        }
        while(count == 0){
            if(r-l+1 < mini){
                mini = r-l+1;
                start_idx = l;
            }
            if(mpp.find(s[l]) != mpp.end()){
                if(mpp[s[l]] == 0){
                    count += 1;
                }
                mpp[s[l]] += 1;
            }
            l += 1;
        }
        r += 1;
    }

    // Stroe the ans in a variable
    if(mini == INT_MAX){
        return "";
    }
    string ans = "";
    for(int i=start_idx; i<start_idx+mini; i++){
        ans += s[i];
    }
    return ans;
}

int main(){
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    string ans = mininSubstring(s, t);
    if(ans == ""){
        cout << "There is no such substring";
    }
    cout << ans;
    return 0;
}
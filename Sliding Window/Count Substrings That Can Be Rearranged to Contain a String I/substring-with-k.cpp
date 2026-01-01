// https://leetcode.com/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-i/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

/*

Example 1:

Input: word1 = "bcca", word2 = "abc"
      
Output: 1

Explanation:

The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.

Example 2:

Input: word1 = "abcabc", word2 = "abc"

Output: 10

Explanation:

All the substrings except substrings of size 1 and size 2 are valid.

Example 3:

Input: word1 = "abcabc", word2 = "aaabc"

Output: 0

*/

long long countSubstrings(string& s, string &t){
    unordered_map<char, int> mpp;
    for(int i=0; i<t.size(); i++){
        mpp[t[i]] += 1;
    }
    int count = mpp.size();
    int l=0, r=0;
    long long ans = 0;
    while(r < s.size()){
        if(mpp.find(s[r]) != mpp.end()){
            mpp[s[r]] -= 1;
            if(mpp[s[r]] == 0){
                count -= 1;
            }
            while(count == 0){
                ans += s.size()-r;
                if(mpp.find(s[l]) != mpp.end()){
                    mpp[s[l]] += 1;
                    if(mpp[s[l]] > 0){
                        count += 1;
                    }
                }
                l += 1;
            }
        }
        r += 1;
    }
    return ans;
}

int main(){
    string s = "dcbdcdccb";
    string t = "cdd";
    long long ans = countSubstrings(s,t);
    cout << ans;
    return 0;
}

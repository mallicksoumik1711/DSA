// https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/?envType=problem-list-v2&envId=sliding-window

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:

Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.                          
*/

int maxOccuranceOfSubstring(string &s, int n, int k, int m){
    //m is useless ignore it.
    int l=0, r=0;
    unordered_map<char, int> mpp;
    unordered_map<string, int> maap;
    int maxi = -1;
    while(r < s.size()){
        mpp[s[r]] += 1;
        if(r-l+1 == k){
            if(mpp.size() <= n){
                int i=l, j=r;
                string str = "";
                while(i <= j){
                    str += s[i];
                    i += 1;
                }
                maap[str] += 1;
                maxi = max(maxi, maap[str]);
            }
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
        }
        while(mpp.size() > n){
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
        }
        r += 1;
    }

    // print the substrings
    for(auto x : maap){
        cout << x.first << " ";
    }
    cout << endl;

    return maxi == -1 ? 0 : maxi;
} 

int main(){
    string s = "aababcaab";
    int maxletters = 2;
    int minSize = 3;
    int maxSize = 4; //completely useless ignore it.
    
    int ans = maxOccuranceOfSubstring(s, maxletters, minSize, maxSize);
    cout << ans;
}

// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include<bits/stdc++.h>
using namespace std;

int allThreeChar(string &s){ 
    unordered_map<char, int> mpp;
    int maxi = 0;
    int l=0, r=0;
    while(r < s.size()){
        mpp[s[r]] += 1;
        while(mpp.size() == 3){
            maxi += s.size()-r;
            mpp[s[l]] -= 1;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l += 1;
        }
        r += 1;

        // for testcase like "acbbcac" it won't work

        // if(mpp.size() == 3){
        //     maxi += s.size() - r;
        //     mpp[s[l]] -= 1;
        //     if(mpp[s[l]] == 0){
        //         mpp.erase(s[l]);
        //     }
        //     l += 1;
        //     if(r != s.size()-1){
        //         r += 1;
        //     }
        // }
        // else{
        //     r += 1;
        // }

    }
    return maxi;
}

int main(){
    string s = "abcabc";
    int ans = allThreeChar(s);
    cout << ans;
    return 0;
}
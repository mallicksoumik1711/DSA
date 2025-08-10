// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=problem-list-v2&envId=two-pointers

/*
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

#include<bits/stdc++.h>
using namespace std;

int containDuplicateVia_Nested_Loops(string &s, string &t){
    for(int i=0; i<s.size(); i++){
        int idx = i;
        for(int j=0; j<t.size(); j++){
            if(s[idx+j] != t[j]){
                break;
            }
            if(j == t.size()-1 && s[idx+j] == t[j]){
                return i;
            }
        }
    }
    return -1;
}


int containDuplicateVia_Sliding_Window(string &s, string &t){
    unordered_map<int, int> mpp;
    vector<int> store;
    for(int i=0; i<t.size(); i++){
        mpp[t[i]] += 1;
    }
    int l=0, r=0, count = t.size();
    while(r < s.size()){
        if(mpp.find(s[r]) != mpp.end()){
            if(mpp[s[r]] > 0){
                count -= 1;
            }
            mpp[s[r]] -= 1;
        }
        while(r-l+1 == t.size()){
            if(count == 0){
                store.push_back(l);
            }
            if(mpp.find(s[l]) != mpp.end()){
                mpp[s[l]] += 1;
                if(mpp[s[l]] > 0){
                    count += 1;
                }
            }
            l += 1; 
        }
        r += 1;
    }
    for(int i=0; i<store.size(); i++){
        int idx = store[i];
        count = t.size();
        for(int j=idx; i<count+idx; j++){ //idx = any number that could be greater than the first index of t
            if(s[j] != t[j-idx]){
                break;
            }
            count -= 1;
            if(count == 0){
                return idx; //store[i]
            }
        }
    }
    return -1;
}

int main(){
    string s = "leetcode";
    string t = "leeto";
    // cout << containDuplicateVia_Nested_Loops(s, t);
    cout << containDuplicateVia_Sliding_Window(s, t);
}
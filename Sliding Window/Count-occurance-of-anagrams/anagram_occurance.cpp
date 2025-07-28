// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include<bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p) {
        vector<int> idx;
        unordered_map<char, int> mpp;
        for(int i=0; i<p.size(); i++){
            mpp[p[i]] += 1;
        }
        int count = mpp.size();
        int l=0, r=0;
        while(r < s.size()){
            if(mpp.find(s[r]) != mpp.end()){
                mpp[s[r]] -= 1;
                if(mpp[s[r]] == 0){
                    count -= 1;
                }
            }
            while(r-l+1 == p.size()){
                if(count == 0){
                    idx.push_back(l);
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
        return idx;
    }

int countOccurance(string &s, string &t){
    unordered_map<char, int> mpp;
    for(int i=0; i<t.size(); i++){
        mpp[s[i]] += 1;
    }

    int count = mpp.size();
    int ans = 0;
    int r=0, l=0;

    while(r < s.size()){
        if(mpp.find(s[r]) != mpp.end()){
            if(mpp[s[r]] > 0){
                count -= 1;
            }
            mpp[s[r]] -= 1;
        }
        if(r-l+1 == t.size()){
            if(count == 0){
                ans += 1;
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
    return ans;
}

int main(){
    string s = "forxxorfxdofr";
    string t = "for";
    int ans = countOccurance(s, t);
    cout << ans;
    return 0;
}

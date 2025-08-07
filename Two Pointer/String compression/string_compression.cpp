// https://leetcode.com/problems/string-compression/description/?envType=problem-list-v2&envId=two-pointers

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
*/

int compressString(vector<char> &s){
    string str = "";
    int i=0, j=0, count = 0;
    while(j < s.size()){
        while(j < s.size() && s[i] == s[j]){
            count += 1;
            j += 1;
        }
        str += s[i];
        if(count > 1){
            str += to_string(count);
        }
        count = 0;
        i = j;
    }
    int result = str.size();
    s.clear();
    for(int i=0; i<result; i++){
        s.push_back(str[i]);
    }
    return result;
}

int main(){
    vector<char> character_array = {'a','a','b','b','c','c','c'};
    int ans = compressString(character_array);
    for(int i=0; i<ans; i++){
        cout << character_array[i] << " ";
    }
    cout << endl;
    cout << ans;
}
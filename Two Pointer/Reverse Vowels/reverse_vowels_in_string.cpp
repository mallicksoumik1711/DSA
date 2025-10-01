// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:                           

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:

Input: s = "leetcode"

Output: "leotcede"
*/

bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
            return true;
        }
        return false;
    }

void reverseVowels(string &s){
    int i=0, j=s.size()-1;
    while(i < j){
        if(!isVowel(s[i])){
            i += 1;
        }
        if(!isVowel(s[j])){
            j -= 1;
        }
        while(s[i] == ' '){
            i += 1;
        }
        while(s[j] == ' '){
            j -= 1;
        }
        if(isVowel(s[i]) && isVowel(s[j])){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i += 1;
            j -= 1;
        }
    }
}

int main(){
    string s = "race a car";
    reverseVowels(s);
    cout << s;
    return 0;
}

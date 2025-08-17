// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

#include<bits/stdc++.h>
using namespace std;

/*
Input: n = 3, m = 27
Output: 3
Explanation: 33 = 27
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 4, m = 625
Output: 5
Explanation: 54 = 625
*/

int helperFunction(int mid, int n, int m){  // 0 if mid == m
    int prod = 1;                           // 1 if mid < m
    while(n){                               // 2 if mid > m
        prod *= mid;
        if(prod > m){
            return 2;
        }
        n -= 1;
    }
    return (prod == m) ? 0 : 1;
}

int nthRoot(int n, int m){
    int l=1, h=m;
    int ans = -1;
    while(l <= h){
        int mid = (l+h)/2;
        int root = helperFunction(mid, n, m);
        if(root == 0){
            return mid;
        }
        else if(root == 1){
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 2, m=81;
    int ans = nthRoot(n, m);
    cout << ans;
    return 0;
}
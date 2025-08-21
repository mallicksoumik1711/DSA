// https://leetcode.com/problems/sqrtx/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

int sqrtX(int x){
    int l=1, h=x;
    int ans = 0;
    while(l <= h){
        long long mid = (l+h)/2;
        if(mid*mid <= x){
            ans = mid;
            l = mid+1;
        }
        else{
            h = mid-1;
        }
    }
    return ans;
}

int main(){
    int x = 2147395599;
    int ans = sqrtX(x);
    cout << ans;
    return 0;
}
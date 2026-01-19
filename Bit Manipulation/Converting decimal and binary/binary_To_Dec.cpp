#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int num){
    int count = 0;
    int ans = 0;
    while(num != 1){    
        int rem = num % 10;
        ans += rem * pow(2, count);
        count += 1;
        num /= 10;
    }
    ans += 1*pow(2,count);
    return ans;
}

int binaryToDecimal_stringInput(string s){
    int i = s.size()-1;
    int res = 0;
    int count = 0;
    while(count < s.size()){
        int num = s[i] - '0'; //converting to num
        res += num * pow(2, count);
        count += 1;
        i -= 1;
    }
    return res;
}

int main(){
    int num = 110;
    int decimal = binaryToDecimal(num);
    int decimalFromString = binaryToDecimal_stringInput(s);
    // cout << "Decimal of " << num << " is: " << decimal << endl;
    cout << "Decimal when string input: "<< decimalFromString << endl;
    cout << (13 & 7) << endl;
    return 0;
}

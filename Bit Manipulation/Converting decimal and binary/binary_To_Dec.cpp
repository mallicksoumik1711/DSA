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

int main(){
    int num = 110; // not checked for entire test cases. probably work for all the testcase
    int decimal = binaryToDecimal(num);
    cout << "Decimal of " << num << " is: " << decimal << endl;
    return 0;
}

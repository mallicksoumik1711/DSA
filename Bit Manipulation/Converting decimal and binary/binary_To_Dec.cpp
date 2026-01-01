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
    int num = 110;
    int decimal = binaryToDecimal(num);
    cout << "Decimal of " << num << " is: " << decimal << endl;
    return 0;
}
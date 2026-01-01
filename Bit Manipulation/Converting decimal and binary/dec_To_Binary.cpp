#include<iostream>
using namespace std;

string decimalToBinary(int num){
    string res = "";
    while(num != 1){
        int r = num%2;
        num /= 2;
        res += to_string(r);
    }
    res +="1";
    string ans = "";
    for(int i=res.size(); i>=0; i--){
        ans += res[i];
    }
    return ans;
}

int main(){
    int num = 13;
    string binary = decimalToBinary(num);
    cout << "Binary of " << num << " is: " << binary << endl;
    return 0;
}
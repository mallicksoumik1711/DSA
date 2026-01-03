#include<iostream>
using namespace std;

bool checkSetBit_via_left_shift_operator(int n, int i){
    return (n & (1 << i));
}

bool checkSetBit_via_right_shift_operator(int n, int i){
    return (n >> i) & 1;
}

int main(){
    int n = 13;
    int i = 1;
    //to check if the 2 bit of 13 is set or not
    // 13 -> 1101, from last 2nd bit is set.
    // for i=2 it will be true, for i=1 false
    bool isSet = checkSetBit_via_left_shift_operator(n, i);
    bool isSet2 = checkSetBit_via_right_shift_operator(n, i);
    if(isSet){
        cout << "The " << i << " bit is set in " << n << endl;
    } else {
        cout << "The " << i << " bit is not set in " << n << endl;
    }
    if(isSet2){
        cout << "The " << i << " bit is set in " << n << " (via right shift operator)" << endl;
    } else {
        cout << "The " << i << " bit is not set in " << n << " (via right shift operator)" << endl;
    }
    return 0;
}
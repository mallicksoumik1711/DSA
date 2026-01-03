#include <iostream>
#include<algorithm>
using namespace std;

// this method will surely give TLE for large numbers

string toBinary(int n){
    string str = "";
    while(n != 1){
       int rem = n % 2;
       str += to_string(rem);
       n /= 2;
    }
    str += "1";
    reverse(str.begin(), str.end());
    return str;
}

int bitConvert(int s, int g)
{
    int zor = s ^ g;
    string binary = toBinary(zor);
    cout << binary << endl;
    int count = 0;
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '1')
        {
            count += 1;
        }
    }
    return count;
}

// optimal approach
int totalConversions(int start, int goal){
    int zor = start ^ goal;
    int count = 0;
    while(zor){
        if(zor & 1){
            count += 1;
        }
        zor >> 1;
    }
    return count;
}

int main()
{
    int start = 10;
    int goal = 7;

    // int ans = bitConvert(start, goal);
    // cout << ans;

    int ansOptimal = totalConversions(start, goal);
    cout << ansOptimal;
    return 0;
}
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include<bits/stdc++.h>
using namespace std;

/*
Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
Example 2:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
Example 3:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
*/

bool helperFunction(vector<int> &nums, int mid, int m, int k){
    long long sum = 0, count = 0;
    for(int i=0; i<nums.size(); i++){
        if(mid >= nums[i]){
            count += 1;
        }
        else{
            sum += count/k;
            count = 0;
        }
    }
    sum += count/k;
    if(sum >= m){
        return true;
    }
    return false;
}
int bloomFlowersBouquets(vector<int> &nums, int m, int k){
    int l = *min_element(nums.begin(), nums.end());
    int h = *max_element(nums.begin(), nums.end());
    int ans = 0;

    long long bouquets = m , adjascent_flowers = k;
    if(bouquets*adjascent_flowers > nums.size()) return -1;

    while(l <= h){
        int mid = (l+h)/2;
        bool isBloomed = helperFunction(nums, mid, m, k);
        if(isBloomed){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {7,7,7,7,12,7,7};
    int m = 2, k = 3;
    int ans = bloomFlowersBouquets(nums, m, k);
    cout << ans;
    return 0;
}
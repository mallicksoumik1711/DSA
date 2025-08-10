// https://leetcode.com/problems/sort-colors/description/

/* DUTCH NATIONAL FLAG ALGO
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/

#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& nums){
    /*  
        1. 0 -> low-1 => all 0's
        2. low -> mid-1 => all 1's
        3. mid -> high => unsorted array
        4. high+1 -> n-1 => all 2's 
    */

    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high){
        if(nums[mid] == 0){
            int temp = nums[mid];
            nums[mid] = nums[low];  
            nums[low] = temp;
            mid += 1;
            low += 1;
        }
        else if(nums[mid] == 1){
            mid += 1;
        }
        else{
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            high -= 1;
        }
    }
}

int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortArray(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
}
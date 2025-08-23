// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

/*    
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

bool rotatedSortedArray_2(vector<int> &nums, int target){
    int l=0, h=nums.size()-1;
    while(l <= h){
        int mid = (l+h)/2;

        //important here 
        if(l != mid && nums[l] == nums[mid]){
            l += 1;
            continue;
        }
        if(mid != h && nums[mid] == nums[h]){
            h -= 1;
            continue;
        }
    
        if(nums[mid] == target){
            return true;
        }
        else if(nums[l] <= nums[mid]){
            if(target >= nums[l] && target <= nums[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        else{
           if(target >= nums[l] && target <= nums[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            } 
        }
    }
    return false;
}

int main(){
    vector<int> nums = {1,0,1,1,1};
    int target = 90;
    string ans = rotatedSortedArray_2(nums, target) == 1 ? "True" : "False";
    cout << ans;
}

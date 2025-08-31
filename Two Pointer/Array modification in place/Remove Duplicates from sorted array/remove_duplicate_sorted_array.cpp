// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=problem-list-v2&envId=two-pointers

#include<bits/stdc++.h>
using namespace std;

/*

Example 1:     

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

*/

/* IMPORTANT
    Here the question is asking you to remove the duplicates from the sorted array such that the first n elements in the input array
    will be unique. It doesn't matter after the first n elements what exactly is there
*/

int removeDuplicates(vector<int> &nums){
    int i=0, j=0;
    while(j < nums.size()){
        if(nums[i] != nums[j]){
            i += 1;
            nums[i] = nums[j];
        }
        j += 1;
    }
    return i+1; //i is at position where afterwards elements could repeat, so we need total numbers so i+1;
}

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    set<int> st;
    int ans = removeDuplicates(nums);

    for(int i=0; i<ans; i++){
        if(st.find(nums[i]) != st.end()){
            cout << "Something went wrong, here the duplicate character is appearing";
            break;
        }
        st.insert(nums[i]);
    }

    if(ans == st.size()){
        cout << "Operation successful"<<endl;
    }
    cout << ans;
}

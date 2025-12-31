#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums = {2,1,5,4,3,0,0};
    int n = nums.size();
    if (n < 2) return 0;

   // Generate all permutations! the first one greater than  the nums array no. is the ans
   // very impractical
   
   // better- but how to implement it?
//    next_permutation(nums.begin(),nums.end());
//    for(int i=0;i<n;i++){
//     cout << nums[i] << " ";
//    }
 
   // Optimal
   int index = -1;
   for(int i = n - 2; i >= 0; i--){
     if(nums[i] < nums[i + 1]){
        // find the breakpoint from last to ensure the largest possible prefix-match.
        index = i;
        break;
     }
   }

   if(index == -1){
    // it's clear that arr is descending order. next perm will be reverse of it...
    reverse(nums.begin(), nums.end());
   }
   else{
   // after breakpoint "index", the whole subarray is in descending order...  from the last, the smallest
   // element greater than nums[index] will be the first element greater than it. then you reverse the 
   // subarray after breakpoint since it is still in decreasing order.
     for(int i = n - 1; i > index; i--){
        if(nums[i] > nums[index]){
            int temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
            break;
        }
     }
     reverse(nums.begin() + index + 1, nums.end());
   }

   for(auto it : nums){
       cout << it << " ";
   }

   return 0;
}

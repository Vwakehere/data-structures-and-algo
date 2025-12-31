#include <bits/stdc++.h>
using namespace std;

// array given. return indices of pair whose sum gives target.

int main(){
   vector<int>nums = {2,5,6,8,11};
   int n = nums.size();
   int target = 14;
// Brute force - check for every pair! O(n^2) and O(1) space
//    for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if (nums[i]+nums[j]==target)
//         cout << i << " " << j;
//         break;
//     }
    
//    }

// Better - hashmap. 
// for every nums[i] check if target-nums[i] exists already in the map or not. if not add arr[i] and its index i into the hashmap.
// if found, return. O(nlogn)- ordered map O(n) - best and average case for unordered map. O(n^2) if collisions occur(worst case)
// O(n) space 
// unordered_map <int,int> mpp = {};
// for(int i=0;i<n;i++){
//     int more = target - nums[i];
//     if(mpp.find(more)!=mpp.end()){
//         cout << i << " " << mpp[more];
//         return 0;
//     }
//     mpp[nums[i]]=i;

// }
// cout << "Not found";
// }

// Slightly better - two pointers without hashmap
sort(nums.begin(),nums.end());
int left = 0;
int right = n-1;
while(left<right){
    if(nums[left]+nums[right]<target) left++;
    else if(nums[left]+nums[right]>target) right--;
    else{
        cout << left << " " << right;
        break;
    }
}
}
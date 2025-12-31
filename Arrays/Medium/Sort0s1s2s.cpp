#include <bits/stdc++.h>
using namespace std;
 void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    vector<int>nums = {0,1,2,0,1,2,1,2,0,0,0,1};
    int n= nums.size();

    // brute - sort() fn time- o(nlogn) time o(n) space - merge sort
    // sort(arr.begin(),arr.end());

    //better - count 0s,1s and 2s. O(2n) time. O(1) space
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==0) count0++;
    //     else if(arr[i]==1) count1++;
    //     else count2++;
    // }
    // for(int i=0;i<n;i++){
    //     if(i<count0){
    //         arr[i]=0;
    //     }
    //     else if(i<count0+count1){
    //         arr[i]=1;
    //     }
    //     else{
    //         arr[i]=2;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     cout << arr[i]<< " ";
    // }

    // optimal - dutch national flag algo 
     // O(N) time O(1) space
    int low = 0;
      int mid = 0;
      int high = n-1;
      while(mid<=high){
        if(nums[mid]==0)
        {
            swap(&nums[mid],&nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(&nums[mid],&nums[high]);
            high--;
        }
      }
       
      
        
    }

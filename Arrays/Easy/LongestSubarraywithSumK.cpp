#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {1,3,4};
    int k=1;
    int len= arr.size();
    int sublen = 0;

    // Brute force - generate all subarrays. check for sum of each subarray. if it is k and its len(j-i+1) is > sublen. update it.
    // for(int i=0;i<len;i++){
    //     int sum=0;
    //     for(int j=i;j<len;j++){
    //        sum+=arr[j];
    //        if(sum==k && j-i+1 > sublen){
    //         sublen = j-i+1;
               
    //        }
           
    //     }
    // }
    // cout << sublen;

    // Better - prefix sum. It is the optimal one if array consists of +ves,-ves and 0. 

//     unordered_map <long long, int> mpp = {};
//     int maxlen = 0;
//     long long sum = 0;
//     for(int i=0;i<len;i++){
//        sum += arr[i];
//        if(sum==k){
//           maxlen = max(maxlen, i+1);
//        }
//        int rem = sum - k;
//        if(mpp.find(rem)!=mpp.end()){
//         int len = i-mpp[rem];
//         maxlen = max(maxlen,len);
//        }
//        //    mpp[sum]=i; // this fails if there are 0s or -ves in array [2,0,0,3] for k = 3 would return 1 instead of 3 since
//        // in map the index for key 2 keeps updating. so at the end i-mpp[rem] gives 3-2 = 1. for only +ves, it is good to go.
//       // use this for +ves,-ves and 0 in array.
//       // if key doesn't exist in the map only then add it to the map and store i as its index. Store the as leftmost index for given sum as possible!
//        if(mpp.find(sum)==mpp.end()){
//         mpp[sum]=i;
//        }
    
//     }
//     cout << maxlen;
// }

// Optimal - for arr[i]>=0 only. can't be negative or zero. two pointers!
int left=0; // moves only when sum >k. arr[left] is removed from the sum.
int right=0; // iterates through arr
int maxlen =0;
 int sum =arr[0];
while(right<len){
    while(left<=right && sum > k){
        sum -= arr[left];
        left++;
    }
    if(sum == k) maxlen = max(maxlen,right-left+1);
    right++;
    if(right<len) sum += arr[right];
}
cout << maxlen;}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {-2,-3,4,-1,-2,1,5,-3};
    int n = arr.size();
// Brute force - generate all subarrays. maximum among them is the max sum
// Every subarray is from i to j(j starts from i and ends at n)
// O(n^3) time and O(1) space.

// int maxSum = INT_MIN;
// int sum = 0;
// for(int i=0;i<n;i++){
//    for(int j=i;j<n;j++){
//     int sum = 0;
//     for(int k= i; k<=j;k++){
//         sum += arr[k];
//         maxSum = max(maxSum,sum);
//     }
//    }

// }
// cout << maxSum;
// }


// Better - just add up at every subarray's end
// O(n^2) time and O(1) space.
// int maxSum = INT_MIN;   
// for(int i=0;i<n;i++){
//     int sum = 0;
//     for(int j=i;j<n;j++){
//         sum += arr[j];
//         maxSum = max(maxSum,sum);
//     }
//    }
//    cout <<  maxSum;
// }

// Optimal - kadane's algo O(N) time O(1) space.

int maxSum = INT_MIN;
int sum = 0;
int left = -1;
int right = -1;
int start = 0;
for(int i=0;i<n;i++){
    if (sum == 0) start = i;
    sum += arr[i];
    
    if(sum>maxSum){
        maxSum = sum;
        left = start;
        right = i;

    }

    if(sum<0){
        sum = 0;
    }
    
}
for(int i=left;i<=right;i++){
  cout << arr[i] << " ";
}
}
// given an array. given an N. array of size N-1. Find the missing element from 1 to N

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,2,4,8,7,6,5};
   // 3 is missing from 1 to 8.
    int len = sizeof(arr)/sizeof(arr[0]);
    // no of elements in array is N-1 i.e. 7.
    int N = 8;
    int ans{};
    
    //Brute Force: just search for each no. from 1 to N using linear search.O(N*N) time. O(1) space.
    // for(int i=1;i<=N;i++){
    //     int found = 0;
    //     for(int j=0;j<N-1;j++){
    //         if(arr[j]==i){
    //             found = 1;
    //             break;
    //         }
    //     }
    //     if(!found) cout << i;
    // }

    // Better: hashing. create a 0 to 5 index hash array. put each no. of arr in it. iterate from 1 to N. there would be an index with 0 value. 
    // O(2N) time and O(N) space
    // int hash[N+1]={0};
    // for(int i=0;i<N-1;i++){
    //     hash[arr[i]]=arr[i];
    // }
    // for(int i=1;i<N+1;i++){
    //     if(hash[i]==0) cout << i;
    // }

    // Optimal1 - sum(from 1 to N)= n(n+1)/2. n(n+1)/2 - sum of elements in array gives the missing no!
    // O(N) time and O(1) space
    // int sum = (N*(N+1))/2;
    // int sum_arr =0;
    // for(int i=0;i<N-1;i++){
    //     sum_arr += arr[i];
    // }
    // int missing= sum - sum_arr;
    // cout << missing;

    // Optimal2 - bit manipulation. XOR of 2 same elements is 0. XOR of an element with 0 gives the element!

    /*
     X0R_1 = 1^2^3...^N xor of numbers upto n 
     XOR_2 = 1^2^4...^N missing no. array
      final = XOR_1 ^ XOR_2 i.e 1^1 ^ 2^2 ^ 3 ^ 4^4 ^ 5^5 ^... ^ N^N
      all elements except 3(the missing nos. are paired) so finally it will be 0 ^ 3(missing no.) which gives 3.
    */ 
    /* this can be done in 2 for loops- one for numbers upto n, other for array. but we can do it in one pass.
    */
    int XOR_1=0;
    int XOR_2=0;
    for(int i=0;i<N-1;i++){
        XOR_1 ^= (i+1);// loop runs from 0 to N-2 so we can use i+1 to set up XOR_1(xors of numbers upto N-1 can be done. N remains)
        XOR_2 ^= arr[i]; // XORs of numbers in array
    }
    XOR_1 ^= N; // N remaining in XOR_1 
    int missing = XOR_1 ^ XOR_2;
    cout << missing;




}
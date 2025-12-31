#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {2,2,3,3,1,2,2};
    int n = nums.size();
    // freq of majority element is greater than n/2
    int targetf = n/2;
// Brute - nested for loops. count each element's freq. if it is equal to targetf, stop. O(n^2) time.

    // Better - Just hash it bruh. O(nlogn) + O(n) time for ordered map. O(n) space
    //  map <int,int> mpp ={};
    // for(int i=0;i<n;i++){
    //     mpp[nums[i]]++;
    // }
    // for(auto it:mpp){
    //     if(it.second>targetf) cout << it.first ;
    // }

// Optimal - Moore's voting algorithm. the final 'el' is the majority element if the majority element exists!
int i=0;
int count =0;
int el;
for(int i=0;i<n;i++){
    if(count == 0){
        count = 1;
        el = nums[i];
    }
    if(nums[i]==el) count++;
    else count--;
}
// the final value of count doesn't mean anything.
// check if el is the majority element or not
int freq=0;
for(int i=0;i<n;i++){
    if(nums[i]==el) freq++;
}
if(freq>targetf) cout << el;
}
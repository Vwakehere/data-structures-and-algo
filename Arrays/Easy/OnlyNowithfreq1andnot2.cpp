// find the only number in the array with frequency 1 and not 2.

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>nums = {1,1,2,3,3,4,4};
    int len = nums.size();
    // bit manipulation - a^a = 0 a^0 = a. this means if you xor every element. the ones in pair get cancelled...
    // so at the end it will be 0^2=2 i.e. the only solo element
    int solo = 0;
    for(int i=0;i<len;i++){
        solo ^= nums[i];
    }
    // cout << solo;
    return solo;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    int n = prices.size();

    // Brute - just check for every pair
    // int profit = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int diff = prices[j]-prices[i];
    //         if(diff>profit) profit = diff;
    //     }
    // }
    // cout << profit;

    // Optimal - if we choose to sell the stock on index i. we pick the minimum element from 0 to n-1 as the buying price. 
    // keep track of the minimum element from the left and we are good to go!

    int profit = 0;
    int mini = prices[0];
    for(int i=1;i<n;i++){
        int diff = prices[i]-mini;
        if(diff>profit) profit = diff;
    // as we go from left to right, we constantly update the mini element, if possible to check the minimum element on the left
    // side of prices[i].
        if(prices[i]<mini) mini = prices[i];
    }
    cout << profit;
}
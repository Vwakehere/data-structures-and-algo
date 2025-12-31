#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr = {16, 17, 4, 3, 5, 2};
    int n = arr.size();
    vector<int>result;
  // an element is a leader if it is greater than every element on right
  // so, it an element is greater than maximum on the right, we can say it is a leader
  
   int maxi = INT_MIN;
   for(int i=n-1;i>=0;i--){
    if(arr[i]>=maxi){
        result.push_back(arr[i]);
        maxi = arr[i];
    }
   }
   reverse(result.begin(),result.end());
   for(int i=0;i<result.size();i++){
    cout << result[i] << " ";
   }
}
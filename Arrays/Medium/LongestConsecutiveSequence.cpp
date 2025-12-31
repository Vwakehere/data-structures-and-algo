#include <bits/stdc++.h>
using namespace std;

int main(){
   vector<int>nums ={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
   int n= nums.size();
//    sort(nums.begin(),nums.end());
//    int maxlen = 1;
//     int len = 1;
//    for(int i=1;i<n;i++)
//    {
      
//        if(nums[i]-nums[i-1]==1){
//         len++;
//        }
//        else if(nums[i]-nums[i-1]==0){
//         continue;
//        }
//        else{
//         len = 1; // unequal elements
//        }
//        maxlen = max(maxlen,len);
//    }
//  cout << maxlen;

// massive assumption that finding element in set occurs without collisions.
unordered_set <int> st;
for(int i=0;i<n;i++){
    st.insert(nums[i]);
}

int maxlen = 1;
// this is a o(2n) loop not o(n*n).
for(auto it: st){
    if(st.find(it-1)==st.end()){
        int count = 1;
        int x = it;
        while(st.find(x+1)!=st.end()){
           count ++;
           x++;
        }
        maxlen = max(maxlen,count);
    }
}
cout << maxlen;
}
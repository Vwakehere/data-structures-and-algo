#include <bits/stdc++.h>
using namespace std;

int main(){
    // vector<int> arr={3,1,-2,-5,2,-4};
    // int n  = arr.size();
    // have to arrange in + - + - format
    // array has even length.
    // 0,2,4,6,8,... n-2 should be occupied by +ve
    // 1,3,...,n-1 should be -ve.
    // order of same sign elements should be preserved
//  vector<int>pos={};
//   vector<int>neg = {};
// // // Store positive in pos, negative in neg
// // // len of pos and neg are guaranteed to be N/2.
// // O(N)+O(N/2) time , O(N) space.
//  for(int i=0;i<n;i++){
//        if(arr[i]>=0) pos.push_back(arr[i]);
//       else neg.push_back(arr[i]);
// //     }
//  for(int i=0;i<n/2;i++){
//     arr[2*i]=pos[i];
//     arr[2*i+1]=neg[i];
// }   
// for(int i=0;i<n;i++){
//     cout << arr[i]<< " ";
//  }

// Optimised brute- O(N) time only not O(2n)
// space - O(N).

// int ans[n]={};
// int pos = 0;
// int neg = 1;
// for(int i=0;i<n;i++){
//    if(arr[i]<0){
//     ans[neg]=arr[i];
//     neg += 2;
//    }
//    else if(arr[i]>=0){
//     ans[pos]=arr[i];
//     pos+=2;
//    }
// }
// for(int i=0;i<n;i++){
//     cout << ans[i] << " ";
// }

// Variation
// What if equal number of +ve and -ve elements aren't there?

vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0,-8};
int len = arr.size();
vector<int>pos;
vector<int>neg;
for(int i=0;i<len;i++){
    if(arr[i]<0) neg.push_back(arr[i]);
    else pos.push_back(arr[i]);
}
if(pos.size()>neg.size()){
    for(int i=0;i<neg.size();i++){
         arr[2*i]=pos[i];
         arr[2*i+1]=neg[i];
    }
    int index = neg.size()*2;
    for(int i= neg.size();i<pos.size();i++){
        arr[index]=pos[i];
        index++;
    }
}
else{
     for(int i=0;i<pos.size();i++){
         arr[2*i]=pos[i];
         arr[2*i+1]=neg[i];
    }
    int index = pos.size()*2;
    for(int i= pos.size();i<neg.size();i++){
        arr[index]=neg[i];
        index++;
    }
}
for(int i=0;i<len;i++){
    cout << arr[i] << " ";
}
}
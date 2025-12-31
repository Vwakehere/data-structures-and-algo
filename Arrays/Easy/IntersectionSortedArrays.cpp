#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A = {1,2,2,3,3,4,5,6};
    vector<int> B = {2,3,3,5,6,6,7};
    int n1 = A.size();
    int n2 = B.size();
    int i=0;
    int j=0;
    vector<int>result;
    while(i<n1 && j<n2){
    if(A[i]<B[j]){
        i++;
    }
    else if(B[j]<A[i]){
        j++;
    }
    // both are equal.
    else{
       
        result.push_back(A[i]);
        i++;
        j++;
    }
    }
    // if either is exhausted, we stop since the remaining elements won't have a corresponding partner
    for(auto it: result){
        cout << it << " ";
    }
}
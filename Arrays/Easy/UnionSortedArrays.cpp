#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr1[]={1,1,2,3,4,5};
    int arr2[]={2,3,4,4,5};
    // union[]={1,2,3,4,5} i.e. sorted and no duplicates.
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // brute force - use a set since "unique" and "sorted". store in result array.
    // O(n1logn+n2logn)+O(n1+n2) time. Space O(n1+n2)+O(n1+n2) one for set, other for result arr(just to return the output)
    
    // set <int> st;
    // // O(n1logn) where n is the no. of elements inserted during iteration
    // for(int i=0;i<n1;i++){
    //     st.insert(arr1[i]);
    // }
    // // O(n2logn)
    // for(int i=0;i<n2;i++){
    //     st.insert(arr2[i]);
    // }
    // int result[st.size()];
    // int i=0;
    // // O(n1+n2) worst case both n1 and n2 elements are included.
    // for(auto it: st){
    //     result[i]=it;
    //     i++;
    // }
    // for(int i=0;i<st.size();i++){
    //     cout << result[i] << " ";
    // }

    //optimal- 2 pointers. both arrays are sorted. use that
    // time- O(n1+n2) space- O(n1+n2) at worse(that too just to return the answer only. the algo didn't require it)
    int i=0;
    int j=0;
    vector <int> result;
    // O(n1+n2)
    while(i<n1 && j<n2){
      if(arr1[i]<=arr2[j]){
        if(result.size()==0 || result.back()!=arr1[i]){
            result.push_back(arr1[i]);
        }
        i++;
      
      }
      else{
        if(result.size()==0 || result.back()!=arr2[j]){
            result.push_back(arr2[j]);
        }
        j++;
      
      }
    
    }
    while(i<n1){
        if(result.size()==0 || result.back()!=arr1[i]){
            result.push_back(arr1[i]);
        }
        i++;
    }
      while(j<n2){
        if(result.size()==0 || result.back()!=arr2[j]){
            result.push_back(arr2[j]);
        }
        j++;
    }
    for(auto it: result){
        cout << it << " ";
    }





}
// Write a program to left rotate an array by d places

#include <bits/stdc++.h>

using namespace std;

void customReverse(int arr[],int start, int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
}
}

int main(){
    
    int arr[]={1,2,3,4,5,6,7,8,9};
    int arr_size= 9;
    int d = 5;
    d = d%arr_size; // since 9 rotatation will have no effect. 8 rotations will be same as 1 rotation and so on...


    // Brute force approach since it uses extra temp[] space. O(n+d) time and O(d) space.

    // // temp array to store elements that will be shifted in back
    // int temp[d]={0};
    // for(int i=0;i<d;i++){
    //   temp[i]=arr[i];
    // }
    // // shifting elements from dth index to the left arr[d] will be assigned to arr[0]...
    // for(int i=d;i<n;i++){
    //     arr[i-d]=arr[i];
    // }
    // for(int i=n-d;i<n;i++){
    //     arr[i]=temp[i-(n-d)]; // arr[n-d] must get temp[0],
    //     // the position next to it gets the next element in temp... so we can express it in the form of distance from n-d.
    // }


   // Optimal approach - reverse subarray of first d element, reverse the subarray of n-d elements. 
   //reverse the whole array! O(2n) time and O(1) space!
   // c++ stl has a reverse function
    reverse(arr,arr+d);
   reverse(arr+d,arr+arr_size);
   reverse(arr,arr+arr_size);

   
// customReverse(arr,0,d-1);
// customReverse(arr,d,arr_size-1);
// customReverse(arr,0,arr_size-1);
   
    for(int i=0;i<arr_size;i++){
        cout << arr[i];
    }



}
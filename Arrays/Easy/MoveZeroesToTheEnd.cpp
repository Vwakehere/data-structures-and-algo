#include <bits/stdc++.h>
using namespace std;
int main(){
 vector <int> nums ={1,0,2,3,2,0,0,4,5,1};
 int len = nums.size();
       int j=-1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
       }
       if(j==-1) return j;
       for(int i=j+1;i<len;i++){
        if(nums[i]!=0){
            int temp= nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
       }
   for(int i=0;i<len;i++){
    cout << nums[i]<< " ";
   }

}
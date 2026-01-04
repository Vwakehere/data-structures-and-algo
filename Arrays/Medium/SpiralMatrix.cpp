#include <bits/stdc++.h>
using namespace std;
// Important!

int main(){
    vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int left = 0;
    int bottom = m-1;
    int right = n-1;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            cout << matrix[top][j] << " ";
        }
        // inside the loop after incrementing,decrementing top,left,bottom,right the base conditions top<=bottom and left<=right can be altered. so we must place those checks 
        // whenever needed.
        top++;
        // top is incremented. so we need to check if top<=bottom. the next for loop does check that.
        for(int i=top;i<=bottom;i++){
            cout << matrix[i][right] << " ";
        }
        right--;
      // right has been decremented, top has been incremented. the for loop does check if right>=left but doesn't check top<=bottom. so we need to check that.
        if(top<=bottom){
        for(int j=right;j>=left;j--){
            cout << matrix[bottom][j]<< " ";
        }
    }
    
        bottom--;
        // top, right and bottom have changed. the for loop does check if bottom>=top. we need to make sure to check left<=right!
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            cout << matrix[i][left] << " ";
        }
    }
        left++;
    }
}
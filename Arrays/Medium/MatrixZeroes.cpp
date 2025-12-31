#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int m = matrix.size();
    int n = matrix[0].size();
 // We need the set the row and column of a 0 element entirely 0
 // Brute -
 // store indices where elements are zero and set their rows and columns zero...
 // without storing if we blindly turn every row and column of every zero element 0, the whole matrix may turn zero
// O(m*n) space O(m*n)+)(x*m*n)
 vector<vector<int>>indices;
 for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0){
            indices.push_back({i,j});
        }
    }
 }
   int row = indices.size();
   int col = 2;
 for(int i=0;i<row;i++){
        if(matrix[indices[i][0]][indices[i][1]]==0){
           for(int k=0;k<m;k++){
            matrix[k][indices[i][1]]=0;
           }
           for(int k=0;k<n;k++){
            matrix[indices[i][0]][k]=0;
           }
        }
    }

 for(int i=0;i<m;i++){
    cout << "[ ";
    for(int j=0;j<n;j++){
        cout << matrix[i][j] << " ";
    }
    cout << "]";
 }

}
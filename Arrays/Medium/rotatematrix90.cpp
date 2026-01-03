#include <bits/stdc++.h>
using namespace std;

void rowReverse(vector<int>&matrixrow,int n){
  for(int i=0;i<=n/2;i++){
    int temp = matrixrow[i];
    matrixrow[i]=matrixrow[n-1-i];
    matrixrow[n-1-i]=temp;
  }
}

int main(){
    /*
    1 2 3 4 
    5 6 7 8
    9 10 11 12
    13 14 15 16 
    becomes 
    13 9  5 1
    14 10 6 2
    15 11 7 3
    16 12 8 4
 Brute - observe the trend. First row becomes last column upon rotation. Second row becomees second last column and so on...
    create another matrix and store the result in it. return it.
    O(n*n) space. O(n*n) time.
    */
   // given n*n matrix.
   vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   int n = matrix.size();
//    vector<vector<int>>result(matrix);
//    for(int i=0;i<m;i++){
//       for(int j=0;j<n;j++){
//         result[j][n-1-i]=matrix[i][j];
//       }
//    }
//    for(int i=0;i<m;i++){
//     cout << "[ ";
//     for(int j=0;j<n;j++){
//         cout << result[i][j] << " ";
//     }
//     cout << " ]";
//    }

   /*Optimal(O(1) space)- transpose and inverting matrix gives the same effect!
   */
   // transpose:
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        int temp = matrix[j][i];
        matrix[j][i]=matrix[i][j];
        matrix[i][j]=temp;
    }
   }
   // reverse
   for(int i=0;i<n;i++){
     rowReverse(matrix[i],n);
   }
  
   for(int i=0;i<n;i++){
    cout << "[ ";
     for(int j=0;j<n;j++){
        cout << matrix[i][j] << " ";
    }
    cout << " ]";
   }

}
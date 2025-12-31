#include <bits/stdc++.h>
using namespace std;
// IMPORTANT 
void markrow(vector<vector<int>>&matrix,int i,int n){
    for(int j=0;j<n;j++){
        if(matrix[i][j]!=0){
            // if -1 is a value in the matrix too... INT_MIN and INT_MAX as well just go on with 
            matrix[i][j]=-1;
        }
    }
}
void markcol(vector<vector<int>>&matrix,int j,int m){
    for(int i=0;i<m;i++){
        if(matrix[i][j]!=0){
            matrix[i][j]=-1;
        }
    }
}

int main(){
    vector<vector<int>>matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int m = matrix.size();
    int n = matrix[0].size();
 // We need the set the row and column of a 0 element entirely 0
 // Brute -
 // store indices where elements are zero and set their rows and columns zero...
 // without storing if we blindly turn every row and column of every zero element 0, the whole matrix may turn zero

 //Brute - if a given element is 0, we marks all the other elements
 // of the row and column as -1(the value that is guaranteed to not be in a binary matrix...) if they are non zero. after all the iterations
 // these -1s have to become 0.
 // Time - O(m*n*(n+m))+O(n*m)
//  for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         if(matrix[i][j]==0){
//             markrow(matrix,i,n);
//             markcol(matrix,j,m);
//         }
//     }
//  }

//  for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         if(matrix[i][j]==-1){
//             matrix[i][j]=0;
//         }
//     }
//  }
 

// Better intuition- an element would be 0 if there is 
// at least one zero in its row or column. Keep a track of that using 2 arrays

// Time - O(2*n*m). O(n)+O(m) space
// vector<int>rows(m);
// vector<int>cols(n);
// for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         if(matrix[i][j]==0){
//             rows[i]=1;
//             cols[j]=1;
//         }
//     }
// }
// for(int i=0;i<m;i++){
//     for(int j=0;j<n;j++){
//         if(rows[i]==1 || cols[j]==1){
//             matrix[i][j]=0;
//         }
//     }
// }

// Optimal - optimise the space somehow...
// use  first row and first column for cols and rows respectively
// but matrix[0][0] is common... we give that to track rows.
// we initialise a variable to track first column...
int col0 = 1;
// matrix[0][1] to matrix[0][n-1] along with col0 track columns
// matrix[0][0] to matrix[0][m-1] tracks zeros in rows
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==0){
            matrix[i][0]=0;
            if( j!=0){
                matrix[0][j]=0;
            }
            else{
                col0 = 0;
            }
        }
    }
}
for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        if(matrix[i][j]!=0){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }
}
if(matrix[0][0]==0){
    for(int j=0;j<n;j++){
        matrix[0][j]=0;
    }
}
if(col0 == 0){
    for(int i=0;i<m;i++){
        matrix[i][0]=0;
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cout << matrix[i][j] << " ";
    }
}

}
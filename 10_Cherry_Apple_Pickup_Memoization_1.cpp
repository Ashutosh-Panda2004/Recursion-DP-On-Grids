#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include <cstring>
using namespace std;

int dp[50][50][50][50];   // considering max size will be 50

bool isValid(vector<vector<int>> vec, int rows, int cols, int r1,int c1, int r2, int c2){
    if(r1<rows && r2<rows && c1<cols && c2<cols && vec[r1][c1]!=-1 && vec[r2][c2]!=-1){
        return true;
    } 
    return false;
}

int recursion(vector<vector<int>> vec, int rows, int cols, int r1,int c1, int r2, int c2){
    
    // Base case
    if(r1==rows-1 && c1==cols-1){
        return vec[r1][c1];
    }
    if(r2==rows-1 && c2==cols-1){
        return vec[r2][c2];
    }
    if(dp[r1][c1][r2][c2]!=-1){
        return dp[r1][c1][r2][c2];
    }
    
    int result = 0;
    
    if(r1==r2 && c1==c2){
        result+=vec[r1][c1];
    }
    else{
        result = result + vec[r1][c1] + vec[r2][c2];
    }
    
    // downDown (both down)
    int downDown = INT_MIN;
    if(isValid(vec, rows, cols, r1+1, c1, r2+1, c2)){
        downDown += recursion(vec, rows, cols, r1+1, c1, r2+1, c2);
    }
    
    // rightRight (both right)
    int rightRight = INT_MIN;
    if(isValid(vec, rows, cols, r1, c1+1, r2, c2+1)){
        rightRight += recursion(vec, rows, cols,r1, c1+1, r2, c2+1);
    }
    
    // downRight (one down, one right)
    int downRight = INT_MIN;
    if(isValid(vec, rows, cols, r1+1, c1, r2, c2+1)){
        downRight += recursion(vec, rows, cols, r1+1, c1, r2, c2+1);
    }
    
    // rightDown (one right, one down)
    int rightDown = INT_MIN;
    if(isValid(vec, rows, cols, r1, c1+1, r2+1,c2)){
        rightDown += recursion(vec, rows, cols, r1, c1+1, r2+1,c2);
    }
    
    dp[r1][c1][r2][c2]  =result + max({downDown, rightRight, downRight, rightDown});
    return dp[r1][c1][r2][c2];
}



int main(){
    
   vector<vector<int>> vec = {{1,1,0,0},{0,1,0,1},{1,1,0,0},{0,1,1,1}};
    int rows = vec.size();
    int cols = vec[0].size();
    int r1=0, c1=0, r2=0, c2=0;
    memset(dp, -1, sizeof(dp));
    
      if(vec[0][0]==-1 || vec[rows-1][cols-1]==-1){
        cout << "Cherries picked up: " << 0;
        return 0;
    }
    
    int ans = recursion(vec, rows,cols, r1, c1, r2, c2);
    
    if(ans<0){
        cout << "Cherries picked up: " << 0;
        return 0;
    }
    
    cout << "Cherries picked up: " << ans;
    
    
    return 0;
}







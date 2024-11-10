#include<iostream>
#include<vector>
using namespace std;


int recursion(vector<vector<int>> grid, int rows, int cols, int r, int c){
    if(r==rows-1 && c==cols-1){
        return 1;
    }

    if(r>=rows || c>=cols ||  grid[r][c]==-1){
        return 0;
    }

    int down=0, right=0;

    if(r+1<rows){
        down = recursion(grid, rows, cols, r+1, c);
    }

    if(c+1<cols){
        right = recursion(grid, rows, cols, r, c+1);
    }

    return down+right;
}


int memoization(vector<vector<int>>grid, int rows, int cols, int r, int c, vector<vector<int>>&dp){

    if(r==rows-1 && c==cols-1){
        return 1;
    }

    if(r>=rows || c>=cols || grid[r][c]==-1){
        return 0;
    }

    if(dp[r][c]!=-1){
        return dp[r][c];
    }

    int down=0, right=0;

    if(r+1<rows){
        down = recursion(grid, rows, cols, r+1, c);
    }

    if(c+1<cols){
        right = recursion(grid, rows, cols, r, c+1);
    }

    dp[r][c] = down+right;   

    return dp[r][c];

}

int tabulation(vector<vector<int>>grid){
    vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),0));
    dp[0][0] = 1;

    for(int r=0;r<grid.size();r++){
        for(int c=0; c<grid[0].size(); c++){

            if(r+1<grid.size() && grid[r+1][c]!=-1){
                dp[r+1][c] += dp[r][c];
            }
            if(c+1<grid[0].size() && grid[r][c+1]!=-1){
                dp[r][c+1] += dp[r][c];
            }

        }

    }

    return dp[grid.size()-1][grid[0].size()-1];
}




int main(){

    vector<vector<int>> grid = {{0,0,0}, {0,-1,0}, {0,0,0}};
    int rows = grid.size();
    int cols = grid[0].size();
    int r=0, c=0;

    if(grid[0][0]==-1){
        cout << "Invalid Starting Point"<< endl;
        return 0;
    }

    if(grid[rows-1][cols-1]==-1){
        cout << "Invalid Ending Point, Impossible Path" << endl;
        return 0;
    }
 
    int paths1 = recursion(grid, rows, cols, r, 0);
    cout << "Number of paths from recursion: " << paths1 << endl;

    vector<vector<int>> dp(rows, vector<int>(cols,-1));
    int paths2 = memoization(grid, rows, cols, r, c, dp);
    cout << "Number of paths from memoization: " << paths2 << endl;


    int paths3 = tabulation(grid);
    cout << "Number of paths from tabulation: " << paths3 << endl;



    return 0;
}

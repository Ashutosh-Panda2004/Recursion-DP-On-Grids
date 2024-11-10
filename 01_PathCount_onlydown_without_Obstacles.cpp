#include <iostream>
#include <vector>
using namespace std;


int recursion(vector<vector<int>> vec, int rows, int cols, int r, int c){
    
    if(r==rows-1 && c==cols-1){
        return 1;
    }
    
    if(r>=rows || c>=cols){
        return 0;
    }
    
    int down = recursion(vec, rows, cols, r+1, c);
    int right = recursion(vec, rows, cols, r, c+1);
    
    
    return down+right;
    
}



int memoization(vector<vector<int>> vec, int rows, int cols, int r, int c, vector<vector<int>>&dp){
    
    if(r==rows-1 && c==cols-1){
        return 1;
    }
    
    if(r>=rows || c>=cols){
        return 0;
    }
    
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    
    int down = recursion(vec, rows, cols, r+1, c);
    int right = recursion(vec, rows, cols, r, c+1);
    
    
    dp[r][c] = down+right;
    return dp[r][c];
    
}

int tabulation(vector<vector<int>> vec, int rows, int cols) {
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    dp[0][0] = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + 1 < rows) {
                dp[i + 1][j] += dp[i][j];
            }
            if (j + 1 < cols) {
                dp[i][j + 1] += dp[i][j];
            }
        }
    }

    return dp[rows - 1][cols - 1];
}

int main()
{
    vector<vector<int>>vec ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = vec.size();
    int cols = vec[0].size();
    
    int r = 0, c  =0;
    if(vec[0][0] == -1){
      cout << "Invalid Starting Point" << endl;
      return 1;
    }

    if(vec[rows-1][cols-1] == -1){
      cout << "No Possible Paths Possible" << endl;
      return 1;
    }
    
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    
    int ans1 = recursion(vec, rows, cols, r, c);
    
    cout << ans1 << endl;
    
    int ans2 = memoization(vec, rows, cols, r, c, dp);
    
    cout << ans2 << endl;
    
    int ans3 = tabulation(vec, rows, cols);
    
    cout << ans3 << endl;
    
    return 0;
}

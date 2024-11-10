#include <iostream>
#include <vector> 
#include <utility>
#include <limits.h>
using namespace std;

void recursion(vector<vector<int>> grid, int rows, int cols, pair<int,int>currpoint, vector<pair<int, int>>&currpath, vector<vector<pair<int,int>>> &paths){
    
    if(currpoint.first == rows-1 && currpoint.second == cols-1){
        currpath.push_back(currpoint);
        paths.push_back(currpath);
        currpath.pop_back();       // Remember this !!!!!
        return;
    }
    
    int r = currpoint.first;
    int c = currpoint.second;
    if(r<rows && r>=0 && c<cols && c>=0 && grid[r][c]!=-1){
        
        currpath.push_back(currpoint);
        
        if(r+1 < rows && grid[r+1][c]!=-1 ){
            recursion(grid, rows, cols, make_pair(r+1, c), currpath, paths);
        }
        if(c+1 < cols && grid[r][c+1]!=-1 ){
            recursion(grid, rows, cols, make_pair(r, c+1), currpath, paths);
        }
        
        currpath.pop_back();
    }
}


int main()
{ 
    vector<vector<int>> grid = {{0,0,0},{0,-1,0},{0,0,0}};
    int rows = grid.size();
    int cols = grid[0].size();
    pair <int, int> currpoint = make_pair(0,0);
    vector<pair<int,int>> currpath;
    vector<vector<pair<int,int>>> ans;
    
    recursion(grid, rows, cols, currpoint, currpath , ans);
    
    vector<pair<int, int>> shortestPath;
    int mini = INT_MAX;
    for (auto path : ans) {
       if(path.size()<mini){
           mini = path.size();
           shortestPath = path;
       }
    }
    
    cout << "Shortest Path is: " << endl;
    for(auto i : shortestPath){
        cout << "(" << i.first << ", " << i.second << ") ";
    }
    
    return 0;
}

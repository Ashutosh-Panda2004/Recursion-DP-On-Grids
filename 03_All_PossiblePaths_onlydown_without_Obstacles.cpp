#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& vec, int rows, int cols, pair<int, int> currpoint, vector<pair<int, int>>& currpath, vector<vector<pair<int, int>>>& ans) {
    if (currpoint.first == rows - 1 && currpoint.second == cols - 1) {
        currpath.push_back(currpoint);
        ans.push_back(currpath);
        currpath.pop_back();
        return;
    }

    int x = currpoint.first;
    int y = currpoint.second;


    if (x >= 0 && x < rows && y >= 0 && y < cols) {
        currpath.push_back(currpoint);

        // Move Right
        if (y + 1 < cols)
            solve(vec, rows, cols, {x, y + 1}, currpath, ans);

        // Move Down
        if (x + 1 < rows)
            solve(vec, rows, cols, {x + 1, y}, currpath, ans);

        // Base case reached tabhi yahan control aaya hai, so backtrack for other possibilities
        currpath.pop_back();
    }
}

int main() {
    vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = vec.size();
    int cols = rows > 0 ? vec[0].size() : 0;

    vector<vector<pair<int, int>>> ans;
    vector<pair<int, int>> currpath;
    pair<int, int> currpoint = make_pair(0, 0);

    solve(vec, rows, cols, currpoint, currpath, ans);

    for (auto path : ans) {
        for (auto point : path) {
            cout << "(" << point.first << "," << point.second << ") ";
        }
        cout << endl;
    }

    return 0;
}


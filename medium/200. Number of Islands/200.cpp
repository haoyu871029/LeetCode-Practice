#include <vector>
#include <iostream>
using namespace std;

class Solution{
    public:
        void dfs(vector<vector<char>>& grid, int i, int j, int m, int n);
        int numIslands(vector<vector<char>>& grid);
};

void Solution::dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    grid[i][j] = '0';
    if (i-1>=0 && grid[i-1][j]=='1')  dfs(grid, i-1,   j, m,n); //上面還有，且上面是1
    if (i+1<m  && grid[i+1][j]=='1')  dfs(grid, i+1,   j, m,n); //下面還有，且下面是1
    if (j-1>=0 && grid[i][j-1]=='1')  dfs(grid,   i, j-1, m,n); //左邊還有，且左邊是1
    if (j+1<n  && grid[i][j+1]=='1')  dfs(grid,   i, j+1, m,n); //右邊還有，且右邊是1
}

int Solution::numIslands(vector<vector<char>>& grid) {
    /* m*n 的二維陣列 */
    int m = grid.size();
    int n = grid[0].size();
    /* main */
    int num = 0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j] == '1'){//找得到1，代表找到一個新的島
                num++; //島的數量+1
                dfs(grid,i,j,m,n); //將這個島的所有1都變成0
            }
        }
    }
    return num;
}

int main(){
    /* build an island */
    vector<vector<char>> grid = {
    {'0','1','0','1','0'},
    {'1','0','0','1','0'},
    {'1','0','1','0','0'},
    {'0','0','0','1','1'}};
    /* Test */
    Solution sol;
    cout << sol.numIslands(grid) << endl;
    return 0;
}

//Compile: g++ -std=c++11 200.cpp -o 200
//Run: ./200
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows);
};

vector<vector<int>> Solution::generate(int numRows) {
    /* Initialization */
    vector<vector<int>> ans; //代表帕斯卡三角形
    for (int i=1; i<=numRows; i++){
        ans.push_back(vector<int>(i, 1));
    }
    /* Processing (DP) */
    for (int i=2; i<numRows; i++){
        int n = ans[i].size();
        for (int j=1; j<=(n-2); j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            //ans[i-1][j-1] 代表左上的值
            //ans[i-1][j] 代表右上的值
        }
    }
    return ans;
}

int main(){
    Solution sol;
    vector<vector<int>> ans = sol.generate(5);
    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//Compile: g++ -std=c++11 118.cpp -o 118
//Run: ./118
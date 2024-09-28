#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex);
};

vector<int> Solution::getRow(int rowIndex) {
    vector<vector<int>> tri;
    for (int i=0; i<=rowIndex; i++){
        tri.push_back(vector<int>(i+1, 1));
    }
    if (rowIndex==0 || rowIndex==1){
        return tri[rowIndex];
    }
    for (int i=2; i<=rowIndex; i++){
        for (int j=1; j<=(i-1); j++){
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }
    return tri[rowIndex];
}

int main() {
    Solution sol;
    vector<int> ans = sol.getRow(3);
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 119.cpp -o 119
//Run: ./119
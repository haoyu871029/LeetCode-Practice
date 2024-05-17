#include <vector> //有包含定義 pair 的標頭檔 <utility>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board);
};

bool Solution::isValidSudoku(vector<vector<char>>& board) {
    set<pair<int,char>> row, col, grid;

    for(int i=0; i<9; i++){//列
        for(int j=0; j<9; j++){//行
            if(board[i][j] != '.'){//非空
                char num = board[i][j];
                /* 檢查列 */
                if (row.find({i,num}) == row.end()) //沒找到
                    row.insert( {i,num} );
                else
                    return false; //找到了，代表是第二次在第i列出現
                /* 檢查行 */
                if (col.find({j,num}) == col.end())
                    col.insert( {j,num} );
                else
                    return false; //找到了，代表是第二次在第j行出現
                /* 檢查3x3 */
                int count = (i/3)*3 + j/3; //計算第幾個九宮格
                if (grid.find({count,num}) == grid.end())
                    grid.insert( {count,num} );
                else
                    return false; //找到了，代表是第二次在第count號九宮格出現
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    cout << sol.isValidSudoku(board) << endl; //expect 1
    return 0;
}

//Compile: g++ -std=c++11 36.cpp -o 36
//Run: ./36
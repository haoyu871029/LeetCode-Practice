#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes);
};

vector<int> Solution::fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    /* Calculate of the fair division */
    int aliceSum = 0, bobSum = 0;
    for (auto i :aliceSizes){
        aliceSum += i;
    }
    for (auto i :bobSizes){
        bobSum += i;
    }
    int k = (aliceSum+bobSum)/2;
    /* Find the answer */
    vector<int> result;
    for (auto x :aliceSizes){
        int need = k-(aliceSum-x);
        for (auto y :bobSizes){
            if (y == need){
                result.insert(result.end(), {x, y});
                return result;
            }
        }
    }
    return result; //should not reach here
}

int main(){
    Solution sol;
    vector<int> aliceSizes = {1, 1};
    vector<int> bobSizes = {2, 2};
    vector<int> result = sol.fairCandySwap(aliceSizes, bobSizes);
    for (auto i :result){
        cout << i << " ";
    }//expect 1 2
    cout << endl;
    return 0;
}

//Compile command: g++ -std=c++11 888.cpp -o 888
//Run command: ./888
//git add . && git commit -m "update 888" && git push origin main
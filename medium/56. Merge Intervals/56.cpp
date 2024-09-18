#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals);
};

vector<vector<int>> Solution::merge(vector<vector<int>>& intervals) { 
    /* edge case */     
    if(intervals.size() == 1)
        return intervals;

    /* pre-sorting */
    vector<pair<int,int>> p;
    for(auto interval :intervals)
        p.push_back({interval[0],interval[1]});
    sort(p.begin(),p.end());

    /* merge intervals */
    vector<vector<int>> ans;
    int f = p[0].first;
    int s = p[0].second;
    for (int i=0; i<p.size()-1; i++){
        if(s >= p[i+1].first) //重疊的情況 ex. [1,4] [2,3]
            s = max(s, p[i+1].second); 
        else{ //不重疊的情況 ex. [1,3] [4,5]
            ans.push_back({f,s});
            f = p[i+1].first;
            s = p[i+1].second;
        }
    } 
    ans.push_back({f,s});
    return ans;
} 

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = sol.merge(intervals);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
    return 0;
}

//Compile: g++ -std=c++11 56.cpp -o 56
//Run: ./56
#include <vector>
#include <string>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
    public:
        vector<string> summaryRanges1(vector<int>& nums);
        vector<string> summaryRanges2(vector<int>& nums);
};

vector<string> Solution::summaryRanges1(vector<int>& nums) {
    int n = nums.size();
    vector<string> result;
    if (n == 0){
        return result;
    }
    int head = nums[0], end;
    for (int i=1; i<=n; i++){
        if (i == n){//要去紀錄最後一段 combo 時
            end = nums[n-1];
            if (head == end){
                result.push_back(to_string(head));
            }
            else{
                result.push_back(to_string(head)+"->"+to_string(end));
            }
        }
        else if (nums[i] != (nums[i-1]+1)){//正常斷 combo 的時候
            end = nums[i-1];
            if (head == end){
                result.push_back(to_string(head));
            }
            else{
                result.push_back(to_string(head)+"->"+to_string(end));
            }
            head = nums[i];
        }
    }
    return result;
}

vector<string> Solution::summaryRanges2(vector<int>& nums) {
    deque<int> q; // double-ended queue (empty, size, push_front, push_back, front, back, clear)
    vector<string> result;
    auto ptr = nums.begin();
    while (ptr != nums.end()){
        if (q.empty() || *ptr==(q.back()+1)){//正常情況: 剛收斂完一個 range，或是接續目前的 range
            q.push_back(*ptr);
            ptr++;
        }
        if (ptr==nums.end() || *ptr!=(q.back()+1)){//要收斂的兩種情況
            string str = "";
            if (q.size() == 1)
                str = to_string(q.front());
            else
                str += to_string(q.front()) + "->" + to_string(q.back());
            result.push_back(str);
            q.clear();
        }
    }
    return result;
}

int main(){
    Solution sol;
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> result = sol.summaryRanges1(nums);
    for (auto str: result){
        cout << str << " ";
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 228.cpp -o 228
//Run: ./228
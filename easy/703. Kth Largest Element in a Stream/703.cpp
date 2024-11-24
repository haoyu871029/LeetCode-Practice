#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums): k(k) {
        for (auto &i :nums){
            pq.push(i);
            if (pq.size() > k){
                pq.pop();
            }
        }
    }
    int add(int val);
};

int KthLargest::add(int val) {
    pq.push(val);
    if (pq.size() > k){
        pq.pop();
    }
    return pq.top();
}

int main(){
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl; // return 4
    cout << kthLargest.add(5) << endl; // return 5
    cout << kthLargest.add(10) << endl; // return 5
    cout << kthLargest.add(9) << endl; // return 8
    cout << kthLargest.add(4) << endl; // return 8
    return 0;
}

//Compile: g++ -std=c++11 703.cpp -o 703
//Run: ./703
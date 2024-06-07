#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head);
};

bool Solution::hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    ListNode *slow = head;
    ListNode *fast = head;
    while(slow!=nullptr && fast!=nullptr){
        fast = fast->next;
        if (fast != nullptr){//若可以一次跑兩步 (若無法則會在下一個迴圈判斷時被檢查到)
            fast = fast->next;
        }
        slow = slow->next;
        if (fast==slow && slow!=nullptr){//fast 倒追 slow 的情況發生
            return true;
        }
    }
    return false; //nullptr 存在於 list 中，代表沒有 cycle
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    Solution sol;
    cout << sol.hasCycle(head) << endl; //expected: true
    return 0;
}

//Compile: g++ -std=c++11 141.cpp -o 141
//Run: ./141
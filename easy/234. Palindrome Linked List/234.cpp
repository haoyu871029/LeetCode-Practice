#include <deque>
#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        bool isPalindrome1(ListNode* head);
        bool isPalindrome2(ListNode* head);
};

bool Solution::isPalindrome1(ListNode* head) { 
    /* I. 計算 node 總數 */
    stack<int> stk;
    ListNode* tmp = head;
    int n = 0;
    while (tmp != nullptr){
        n++;
        tmp = tmp->next;
    }
    /* II. 將第 0 ~ (n/2)-1 個 node 的值推入 stack */
    tmp = head;
    for (int i=0; i<=(n/2)-1; i++){//II.
        stk.push(tmp->val);
        tmp = tmp->next;
    }
    /* III. 將剩下的 node 值和從 stack pop 出來的值作比較。 */
    if (n%2 == 1){//代表 node 總數是奇數
        tmp = tmp->next; //跳過最中間的元素
    }
    while (tmp != nullptr){//III.
        if (tmp->val != stk.top())
            return false;
        stk.pop();
        tmp = tmp->next;
    }
    return true;
}


bool Solution::isPalindrome2(ListNode* head) {
    /* I. 將所有 node 值存入 deque */
    ListNode* tmp = head;
    deque<int> q;
    while (tmp != nullptr){
        q.push_back(tmp->val);
        tmp = tmp->next;
    }
    /* II. 每次比較 deque 的頭尾值是否相同 */
    while (!q.empty()){
        if (q.front() != q.back())
            return false;
        q.pop_front();
        if (!q.empty())
            q.pop_back();
    }
    return true;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    Solution sol;
    cout << sol.isPalindrome2(head) << endl;
    return 0;
}

//Compile: g++ -std=c++11 234.cpp -o 234
//Run: ./234
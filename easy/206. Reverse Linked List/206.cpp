#include <iostream>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution{
    public:
        ListNode* reverseList1(ListNode* head);
        ListNode* reverseList2(ListNode* head);
        ListNode* reverseList3(ListNode* head);
};

ListNode* Solution::reverseList1(ListNode* head) {
    if (head == NULL) return head;
    /* Part 1 */
    ListNode* temp = head;
    stack<int> stk;
    while (temp != nullptr){
        stk.push(temp->val);
        temp = temp->next;
    }
    /* Part 2 */
    ListNode* result = new ListNode();
    temp = result;
    while (!stk.empty()){
        int value = stk.top();
        temp->next = new ListNode(value);
        temp = temp->next;
        stk.pop();
    }
    return result->next;
}

ListNode* Solution::reverseList2(ListNode* head) {
    if (head == NULL) return head;
    /* Part 1 */
    stack<ListNode*> stk;
    while (head != NULL){
        stk.push(head);
        head = head->next;
    }
    /* part 2 */
    ListNode* ans = new ListNode();
    ListNode* temp = ans;
    while (!stk.empty()){
        temp->next = stk.top();
        temp = temp->next;
        stk.pop();
    }
    temp->next = NULL;  // 確保反轉後的鏈表最後一個節點的 next 指向 NULL
    return ans->next;
}

ListNode* Solution::reverseList3(ListNode* head) {
    ListNode* curr = head; //初始設定為 head，用來遍歷原始鏈表
    ListNode* prev = nullptr; //初始設定為 nullptr，用於保存每個節點的前一節點，最終成為反轉後的頭節點。
    ListNode* forward; //用於臨時存儲 curr 的下一個節點，以防在修改鏈接時丟失原來鏈表的後續節點。
    while (curr != nullptr){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* result = sol.reverseList3(head);
    while (result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 206.cpp -o 206
//Run: ./206
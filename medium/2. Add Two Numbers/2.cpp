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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int sum, value, carry = 0;
        while (l1 || l2 || carry){
            sum = 0;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            value = sum % 10;
            carry = sum / 10;
            ListNode* new_node = new ListNode(value);
            temp->next = new_node;
            temp = temp->next;
        }
        return ans->next;      
    }
};
int main(){
    /* Test: 342 + 465 = 807 */

    //342: 2->4->3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    //465: 5->6->4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* result = s.addTwoNumbers(l1,l2);
    while(result != NULL){
        cout << result->val <<" ";
        result = result->next;
    }//Output: 7->0->8

    return 0;
}

//Compile: g++ -std=c++11 2.cpp -o 2
//Run: ./2
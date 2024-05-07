#include <iostream>
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
        ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2);
        ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2);
};

ListNode* Solution::mergeTwoLists1(ListNode* list1, ListNode* list2) {
    ListNode* result = new ListNode();
    ListNode* temp = result;
    ListNode* temp_1 = list1;
    ListNode* temp_2 = list2;
    /* 兩邊都還有的情況下，才做主處理。 */
    while ((temp_1 != nullptr) && (temp_2 != nullptr)){
        int value;
        if (temp_1->val <= temp_2->val){
            value = temp_1->val;
            temp_1 = temp_1->next;
        }
        else if (temp_1->val > temp_2->val){
            value = temp_2->val;
            temp_2 = temp_2->next;
        }
        temp->next = new ListNode(value);
        temp = temp->next;
    }
    /* 因為兩個 list 都已經預排序過，所以若有剩就直接接上去。 */
    if (temp_1 == nullptr){
        temp->next = temp_2;
    }
    else {//temp_2 == nullptr
        temp->next = temp_1;
    }
    return result->next;
}

ListNode* Solution::mergeTwoLists2(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    while(t1 != NULL && t2 != NULL) {
        if(t1->val < t2->val) {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1) temp->next = t1;
    else temp->next = t2;
    return dummyNode->next;
}

int main(){
    /* Build list1 and list2 */
    //list1: 1->2->4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    //list2: 1->3->4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    /* Merge list1 and list2 */
    Solution sol;
    ListNode* result = sol.mergeTwoLists1(list1, list2);
    /* Print result */
    while (result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}

//Compile: g++ -std=c++11 21.cpp -o 21
//Run: ./21
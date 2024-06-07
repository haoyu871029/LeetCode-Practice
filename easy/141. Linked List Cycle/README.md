# 141. Linked List Cycle
## Description & Example
[leetcode](https://leetcode.com/problems/linked-list-cycle/)

Description
```
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 

Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
```
給定一條 linked list's head，判斷這個 linked list 是否具有 cycle。其他線索或限制如下:
- pos 應該是用來測試的
- list 中可能會有重複數字
- list 可能是空的

Example
```
Input: head->3->2->0->-4(->2), pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node
```
## .cpp
想像 A, B 兩個人在跑操場，若 A 一直都跑得比 B 快，那麼 A 一定會在某個時間點倒追 B。這個作法就是利用類似的概念，利用兩個指針 fast 和 slow，fast 每次走兩步，slow 每次走一步，若 cycle 存在，則 fast 一定會在某個時間點和 slow 指向同一個 node (倒追發生)

這個作法的分析如下 (其中 n 是 list 中的 nodes 總數)
- 時間複雜度: O(n)
- 空間複雜度: O(1)

若 list 中的數字不重複，那麼只要在遍歷過程中發現指到出現過的數字，就可以判斷 cycle 存在。程式碼如下:
```cpp
bool hasCycle(ListNode *head) {
    unordered_map<int,int> mp; //記錄遍歷過的數字
    ListNode* tmp = head;
    while (tmp != nullptr){
        if (mp.find(tmp->val) != mp.end()){
            cout << tmp->val;
            return true;
        }
        mp[tmp->val] = 1; //1沒有意義
        tmp = tmp->next;
    }
    return false; //nullptr 存在於 list 中，代表沒有 cycle
}
```

## 206. Reverse Linked List
[leetcode](https://leetcode.com/problems/reverse-linked-list/description/)

給定一個 linked list 的 head，將其反轉並回傳新的 head

Example
- Input: head->1->2->3->4->5
- Output: result->5->4->3->2->1
### .cpp

#### Version 1
1. 利用 stack 去儲存原本 list 中的值
2. 再一一將值 pop 出以建立新的 nodes 給 result 指

過程中利用一個 temp pointer，分別在 Part 1 遍歷原 list，以及在 Part 2 建立新 list
#### Version 2
和 Version 1 一樣都使用 stack，但這次 stack 中存的是指標。
1. 利用 stack 去儲存原本 list 中指向各個 node 的指標
2. 再一一將指標 pop 出給 result 指

測試結果顯示 Version 2 比 Version 1 快，因為 Version 1 建構 result list 的過程中需要多次的 new node 操作。
#### Version 3
直接在遍歷原 list 的過程中建構 result list，這邊用例子來說明比較好理解：

![f1](/easy/206.%20Reverse%20Linked%20List/images/f1.png)

![f2](/easy/206.%20Reverse%20Linked%20List/images/f2.png)

![f3](/easy/206.%20Reverse%20Linked%20List/images/f3.png)
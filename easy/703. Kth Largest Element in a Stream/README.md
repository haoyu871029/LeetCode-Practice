# [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)
## Introduction
完成一個 class `KthLargest`，其中包含 constructor `KthLargest` 及 method `add`。目標是，每次透過 add 在分數列表中加入新的分數時，都能夠回傳目前為止分數列表中第 k 高的分數。

```
KthLargest kthLargest(3, {4,5,8,2})
呼叫順序: add(3), add(5), add(10), add(9), add(4)
回傳順序: 4, 5, 5, 8, 8
```
## .cpp
**< Description >**

constructer:  
先利用一個 min heap 去儲存分數列表中前 k 高的分數。處理方式為每次將 nums 中的一個數取出並加入 min heap，再判斷若 min heap 中存在超過 k 個分數，就將 top，也就是目前第 k+1 高的分數，pop 出來。處理完成後，min heap 的 top 就會是分數列表目前為止第 k 高的分數。  

add:  
每次在 min heap 加入新分數後，使用和 constructer 加入分數同樣的邏輯，去判斷若 min heap 中存在超過 k 個分數，就將 top，也就是目前第 k+1 高的分數，pop 出來。如此一來便可保持 min heap 的 top 一直是第 k 高的分數。

**< Analysis >**
- Time complexity: O(nlogk) / O(logk)
- Space complexity: O(k)
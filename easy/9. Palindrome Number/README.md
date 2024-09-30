# 9. Palindrome Number
[leetcode](https://leetcode.com/problems/palindrome-number/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
判斷一個整數是否為回文數。

```
Example

Input: x = 121
Output: true
```

其他線索或限制如下:
- x 的範圍為 `-2^31 <= x <= 2^31 - 1`，而負數會視為非回文數。
## .cpp
**< Description >**

基本邏輯為，若要判斷 x 是否為回文數，應該去比對其前半數列與後半數列。且若 x 為回文數，x 反轉後仍會是回文數。依照這個邏輯，我的想法是可以將 x 先轉換成 vector 或是 dequeue，而 deque 支援的操作讓後續的比對實作起來會比較直觀，因此選擇 deque

**< Discussions >**
1. 為什麼使用 dequeue 會比使用 vector 更直觀?
    > 因為若使用 vector，不論是掃描的終止條件，或是欲比對的兩個數的位置，都會需要以 index 的處理去判斷或指定。而 deque 支援頭尾的各種操作，使得比對的過程更為直觀。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)

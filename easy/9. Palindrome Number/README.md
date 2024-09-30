# 9. Palindrome Number
[leetcode](https://leetcode.com/problems/palindrome-number/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
判斷一個整數是否為回文數

```
Example

Input: x = 121
Output: true
```

其他線索或限制如下:
- x 的範圍為 `-2^31 <= x <= 2^31 - 1`，而負數會視為非回文數。
## .cpp
**< Description >**

基本邏輯為，若 x 為回文數，代表其前半數列與後半數列會是鏡像的，且 x 反轉後仍會是回文數。因此，我的想法是同時去掃描前半數列與後半數列，每次比對兩個數是否相等。為了實作這個想法，需要先將 x 轉換到一個合適的資料結構，而我選擇 deque，因為 deque 支援頭尾的各種操作，使得比對的過程更為直觀。

**< Discussions >**
1. 為什麼使用 dequeue 會比使用 vector 更直觀?
    > 因為若使用 vector，不論是掃描的終止條件，或是欲比對的兩個數的位置，都會需要以 index 的處理去判斷或指定。而 deque 支援頭尾的各種操作，使得比對的過程更為直觀。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)

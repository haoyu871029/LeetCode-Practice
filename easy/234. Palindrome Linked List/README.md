# 234. Palindrome Linked List
## Description & Example
[leetcode](https://leetcode.com/problems/palindrome-linked-list/description/)

Description
```
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
```
給定一個單向 linked list，判斷其是否為回文。其中 linked list 至少有一個 node，且每個 node 的值域為 [0,9]

Example
```
Input: head -> 1 -> 2 -> 2 -> 1
Output: true
```
## .cpp
### Version 1: stack 法
```
利用 stack 來處理，需遍歷兩次 linked list
I. 第一次遍歷是為了計算 node 總數
II. 第二次遍歷 part 1: 遍歷第 0 ~ (n/2)-1 個 node，將他們的值都推入 stack
III. 第二次遍歷 part 2: 先根據 node 總數決定迴圈要從第 (n/2)+1 個還是 (n/2) 個 node 開始判斷，將這些剩下的 node 值和從 stack pop 出來的值作比較。
這個作法的時間複雜度和空間複雜度都是 O(n)
```
這個作法的分析如下
- 時間複雜度: O(n)，因為總計需要遍歷兩次 linked list
- 空間複雜度: O(n)，因為需要一個 size 為 n/2 的 stack 來存放前半部分的 node 值
### Version 2: deque 法
```
利用 deque 來處理，只需遍歷一次 linked list
I. 遍歷一次 linked list 將所有 node 值存入 deque
II. 遍歷一次 deque，利用 deque 的特性，每次比較頭尾的值是否相同，直到 deque 為空。

這個作法的好處是不需要另外判斷 node 總數是奇數還是偶數，且想法比較直觀，程式碼也較簡潔。
```
這個作法的分析如下
- 時間複雜度: O(n)
    - I. 遍歷一次 linked list 將 node 值存入 deque，時間複雜度為 O(n)
    - II. 遍歷一次 deque 來判斷是否為回文，時間複雜度為 O(n)
- 空間複雜度: O(n)，因為需要一個 size 為 n 的 deque 來存放所有的 node 值，故實際的額外記憶體空間會較 Version 1 多。

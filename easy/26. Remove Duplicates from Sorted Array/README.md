# [26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入一個 non-decreasing 數列 `vector<int>& nums`，本題要求將 `nums` 中出現過的相異數字顯示在數列前段，並回傳新的長度。

```
Example

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: 數列中出現過 0, 1, 2, 3, 4 這五個相異數，因此回傳 5
```

其他線索或限制如下:
- 須以 in-place 的方式實作，即不得使用額外空間。
- 僅要求將前段數列處理好，剩餘的後段數列內容無需處理。
- 前段數列顯示的數字順序須按照原本這些數字的相對順序。
## .cpp
**< Description >**

解題邏輯為，透過一個變數代表目前欲擺放的位置，一個變數代表目前遍歷到的位置，並在遍歷的過程中透過比對相鄰的兩個數字來決定是否要作擺放，而遍歷的速度一定比擺放的速度快。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(1)
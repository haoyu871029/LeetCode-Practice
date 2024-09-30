# 1752. Check if Array Is Sorted and Rotated
[leetcode](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
判斷一段數列是否是由一個 non-decreasing order 數列旋轉而來。  
此題所謂的旋轉指的是數列右移。即一個數列 A 旋轉了 x 位後得到了相同長度的數列 B，會滿足 `A[i] == B[(i+x) % A.length]`

```
Example

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [3,4,5,1,2] 可以由 [1,2,3,4,5] 這個 non-decreasing order 數列從數字 3 旋轉 3 位 (向右移動 3 次) 而來。
```
## .cpp
**< Description >**

基本邏輯為，數列中最大數的前後數列皆須為 non-decreasing order，且後數列中的每個數須皆小於前數列的第一個數。其他的細節是在試的過程中決定的，例如：
- 若最大數不止一個，則取 index 靠前者。
- 後數列起始點的決定

**< Discussions >**
- 為何後數列中的每個數皆需小於前數列的第一個數？
    > 避免像是 `[3,5,6,1,2,4]` 這樣的情況，雖然後數列 `[1,2,4]` 是 non-decreasing order，但回復後 `[1,2,4,3,5,6]` 就不對了。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(1)
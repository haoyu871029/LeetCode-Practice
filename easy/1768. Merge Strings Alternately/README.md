# [1768. Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入兩個字串 `string word1` 和 `string word2`，將兩個字串進行交替合併並回傳。所謂交替合併，即輪流從 `word1` 和 `word2` 取一字元放入回傳字串中，也就是説最後回傳字串完成後會是 `word1[0]-word2[0]-word1[1]-word2[1]-...` 的形式。此外，若其中一個字串比另一個字串長，則將多出來的字元直接接在合併後的字串尾端。

```
Example

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
```

其他線索或限制如下:
- 1 <= `word1.length`, `word2.length` <= 100
- `word1` and `word2` consist of lowercase English letters.
## .cpp
**< Description >**

解題邏輯為，利用一 for 迴圈對兩個字串同時進行遍歷，遍歷範圍為 `i = 0~n-1`，其中 n 為兩個字串中較長的字串長度。每一圈要從兩個字串各自取字元之前，都要先判斷 i 是否還沒超出該字串長度。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)
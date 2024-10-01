# [1684. Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入兩個參數 `string allowed` 與 `vector<string>& words`，其中 `allowed` 表示可用的字母有哪些，而 `words` 則整理了一些單字字串。本題為判斷 `words` 中有幾個字串為 "consistent"，即字串中僅出現 `allowed` 規範的可用字母。

```
Example

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
```

其他線索或限制如下:
- `allowed` 中的字母不重複
- 不論是 `allowed` 或 `words`，出現的字母皆為小寫字母
- 不論是 `allowed`, `words` 或 `words[i]`，皆非空，且皆有限制範圍。
## .cpp
**< Description >**

解題邏輯為，先把 `allowed` 中的每個字母都存到 map 中作為 key，接著遍歷 `words` 中的每個單字，並判斷每個字母是否能在 map 中找到。

**< Analysis >**
- Time complexity: O(n＊k)
    > 其中 n 為 `words` 的可能長度，k 為 `words[i]` 的可能長度，雖然兩者在此題皆有訂定範圍，但這邊假設使用者可決定長度。
- Space complexity: O(1)
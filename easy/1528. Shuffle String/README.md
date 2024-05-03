## 1528. Shuffle String
[leetcode](https://leetcode.com/problems/shuffle-string/)

給定一個字串 s 和一個整數陣列 indices，indices 中的數字代表 s 中對應 index 的字元在新字串中應該要放的位置，請將 s 根據 indices 重新排列成一個新的字串。

Example
- Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
- Output: "leetcode"
### .cpp
- version 1
    > 先利用一個 map 將 indices 中的數字與對應的字元做 mapping，再利用 map 會自動根據鍵值排序的特性，遍歷一遍 map 將每個 value 加入到新的字串中，完成遍歷即可回傳新字串，這樣的做法時間複雜度是 O(nlogn)
- version 2
    > 直接對原本的 s 做更改，但仍需要先複製一份 s 到另一個 string，這樣的做法時間複雜度是 O(n)
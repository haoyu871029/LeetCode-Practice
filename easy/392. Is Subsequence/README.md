## 392. Is Subsequence
[leetcode](https://leetcode.com/problems/is-subsequence/description/)

給定兩個字串 s 和 t，若 s 是 t 的 subsequence，則回傳 true，否則回傳 false。

Example
- Input: s = "abc", t = "ahbgdc"
- Output: true

### .cpp
#### Version 1
可以提前判斷的情況目前想到有三種
1. s 和 t 相同 (true)
2. s 是空字串 (true)
3. s 長度大於 t (false)
4. s 和 t 兩者長度相同，但 s != t (false)
 
若無法提前判斷，就透過遍歷 t 字串來處理，其中變數 k 用來記錄找到的數量，在遍歷過程中當找到與 s 字串中相同的字元時，k++。正常情況下，在遍歷結束前應該要找到 s 字串中所有的字元（也就是 k 應等於 s_num），因此若迴圈結束還沒回傳 true，則回傳 false

這個做法的時間複雜度是 O(t_num)
#### Version 2
和 Version 1 的概念差不多，差別在於遍歷是用 while loop 來處理。

這個做法的時間複雜度也是 O(t_num)
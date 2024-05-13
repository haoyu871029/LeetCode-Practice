## 20. Valid Parentheses
[leetcode](https://leetcode.com/problems/valid-parentheses/)

給定一個只包含 '(', ')', '{', '}', '[' 和 ']' 這幾個字元的字串 s，判斷 s 是否有效 (valid)，有效的條件如下：
1. 左括號必須由相同類型的右括號封閉。
2. 左括號必須以正確的順序關閉。
3. 每個右括號都有一個對應的相同類型的左括號。

Example
- Input: s = "()[]{}"
- Output: true
### .cpp
先將對應關係存至 map 中，再利用一個 stack 來處理，這個做法的時間複雜度是 O(s.size())
## 66. Plus One
- [leetcode](https://leetcode.com/problems/plus-one/description/)
- [chatgpt](https://chat.openai.com/share/d1e786ff-f608-458a-aab5-6ce4385d5d0d)

給定一個由整數陣列表示的大整數，其中每個 digits[i] 代表該大整數的第 i 位，且該大整數中不會有前導 0，請回傳將該大整數加一後的結果陣列。

Example
- Input: digits = [1,2,3]
- Output: [1,2,4]
- Explanation: 
    > The array represents the integer 123.
    > Incrementing by one gives 123 + 1 = 124.
    > Thus, the result should be [1,2,4].
### .cpp
#### Version 1
利用一個反向遍歷的迴圈，藉由判斷當前數字是否為 9 來做對應處理，
#### Version 2
先把每一位的計算結果存入 stack，再將 stack 的內容一一推出存入 ans vector

## 70. Climbing Stairs
- [leetcode](https://leetcode.com/problems/climbing-stairs/description/)
- [chatgpt](https://chat.openai.com/share/6f0f6bdb-3e5c-4cc9-bd0d-56429cb8acc0)

一個共 n 階的樓梯，每次只能爬 1 階或 2 階，回傳有幾種不同的上法。

Example
- Input: n = 3
- Output: 3
- Explanation: 有三種方法可以爬到第三階
  1. 1 階 + 1 階 + 1 階
  2. 1 階 + 2 階
  3. 2 階 + 1 階
### .cpp
#### DP 解
- 爬上第 n 階的最後一步有兩種可能：
  1. 從第 n-1 階爬 1 階到第 n 階
  2. 從第 n-2 階爬 2 階到第 n 階
- 因此到達第 n 階的方法數就是到達第 n-1 階和第 n-2 階方法數的總和。
- 利用兩個 for loops 來建構 dp table
#### 遞迴解
是正確的，但這樣的做法會發生 TLE，因為會有很多結果是被重複計算的。

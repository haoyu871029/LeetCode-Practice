## 2. Add Two Numbers
- [leetcode](https://leetcode.com/problems/add-two-numbers/description/)
- [chatgpt]()

給定 2 non-empty linked lists 分別代表 2 個非負整數，數字在 linked list 中是反向儲存的，且每個節點只會包含一個數字，請回傳兩數和所代表的 linked list。

Example
- Input: l1 = 2->4->3, l2 = 5->6->4
- Output: 7->0->8
- Explanation: 342 + 465 = 807
### .cpp
核心想法是每次處理一位的運算
- sum用來儲存每一位的計算結果
- carry是來自上一位的計算結果
- temp幫ans建立答案
- 最後回傳ans->next，因為ans是dummy node
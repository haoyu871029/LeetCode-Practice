## 101. Symmetric Tree
[leetcode](https://leetcode.com/problems/symmetric-tree/description/)

給定一棵 binary tree，判斷這棵樹是否是對稱的。

Example
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
- Input: root = [1,2,2,3,4,4,3]
- Output: true
### .cpp
若一棵樹為對稱樹，代表其 root 的左右子樹是對稱的，而兩棵樹彼此對稱的條件如下
1. 左右子的值相等
2. 「左子的左子樹」和「右子的右子樹」是對稱的
3. 「左子的右子樹」和「右子的左子樹」是對稱的

因此利用遞迴解，這個解法的時間複雜度是 O(n)，其中 n 是 node 總數，因為每個 node 都會被訪問且檢查一次來確保其對稱性。
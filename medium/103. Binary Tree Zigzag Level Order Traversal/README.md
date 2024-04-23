## 103. Binary Tree Zigzag Level Order Traversal
- [leetcode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
- [chatgpt](https://chat.openai.com/share/90096ba6-d568-4c28-afd6-6ecf6efb5ba9)

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

給定一棵 binary tree 的 root，回傳 the zigzag level order traversal 的結果。所謂 the zigzag level order traversal 是指，(若 root 是第 0 層)偶數層左到右遍歷，奇數層右到左遍歷。

Example
- Input: root = [3,9,20,null,null,15,7]
- Output: [[3],[20,9],[15,7]]
### .cpp
利用一個 queue 來暫存每一層的所有節點

用一個 for loop 來處理每層的節點 (遍歷 queue)，每圈的 part 1 先將目前節點的 value 輸入 nodes vecter 來建構此層的結果 (其中 idx 用來根據目前是奇數或偶數層來決定放入 nodes 的方向)，part 2 再將下一層節點中和目前節點相連的推入 queue 中。
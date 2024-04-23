## 144. Binary Tree Preorder Traversal
[leetcode](https://leetcode.com/problems/binary-tree-preorder-traversal/)

對一棵已建好的 binary tree 進行 preorder traversal，並將遍歷結果存至一個 vector<int> 回傳。

Example
- Input: root = [1,null,2,3]
- Output: [1,2,3]
### .cpp
- 若要採取遞迴的方式，則需要另外寫一個用來遞迴的函數，並將 result vector 透過引用的方式傳入。
- 若要採取迭代的方式，則利用一個 stack 來處理。
## 104. Maximum Depth of Binary Tree
[leetcode](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

給定一棵 binary tree's root，回傳該 binary tree's maximum depth

Example
- Input: root = [3,9,20,null,null,15,7]
```
    3
   / \
  9  20
    /  \
   15   7
```
- Output: 3
### .cpp
利用遞迴解：整顆 binary tree's maximum depth 其實就是 root 左子樹的 maximum depth 和 root 右子樹的 maximum depth，取較大者再加一。
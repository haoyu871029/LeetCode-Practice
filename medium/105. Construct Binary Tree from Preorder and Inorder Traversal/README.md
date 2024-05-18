## 105. Construct Binary Tree from Preorder and Inorder Traversal
- [leetcode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
- [chatgpt](https://chat.openai.com/share/bb0d12dd-864d-4911-867c-ef6e365e157c)

給定兩個整數陣列，preorder 和 inorder，其中 preorder 是二元樹的前序遍歷，inorder 是相同樹的中序遍歷，請構建並返回該二元樹。

Example
- Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
- Output: [3,9,20,null,null,15,7]
### .cpp 
```
       3
     /   \
    9    20
  /  \  /  \
 1    2 5   7
```
- Given
    - preorder = {3,9,1,2,20,5,7}
    - inorder = {1,9,2,3,5,20,7}
    - mp = { {1,0}, {9,1}, {2,2}, {3,3}, {5,4}, {20,5}, {7,6} }
- 利用 buldTree() 作為建構樹的主函數，先將各個 node 以 inorder index 來建立一個 map
- 利用 constructTree() 遞迴建立子樹，每一次呼叫 constructTee() 時來建樹時：
    - 用 left_num 來控制左右子樹 preorder 的範圍
    - 用 root_pos 來控制左右子樹 inorder 的範圍

![ex](/medium/105.%20Construct%20Binary%20Tree%20from%20Preorder%20and%20Inorder%20Traversal/images/example.png)

- 多寫一個 postorder 來檢查 binary tree 是否構建正確。
- 有試著封裝成 Class，存在 Algorithm-Practice 資料夾中。
### .py
### .c
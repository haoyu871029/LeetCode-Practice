## 105. Construct Binary Tree from Preorder and Inorder Traversal
- [leetcode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
- [chatgpt](https://chat.openai.com/share/bb0d12dd-864d-4911-867c-ef6e365e157c)

給定兩個整數陣列，preorder 和 inorder，其中 preorder 是二元樹的前序遍歷，inorder 是相同樹的中序遍歷，請構建並返回該二元樹。

Example
- Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
- Output: [3,9,20,null,null,15,7]
### .cpp 
- 利用 buldTree() 作為建構樹的主函數，並利用 constructTree() 遞迴建立子樹。
- 多寫一個 postorder 來檢查 binary tree 是否構建正確。
- 有試著封裝成 Class，存在 Algorithm-Practice 資料夾中。
### .py
### .c
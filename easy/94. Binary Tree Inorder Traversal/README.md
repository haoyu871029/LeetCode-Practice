# 94. Binary Tree Inorder Traversal
## Description
[leetcode](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

Description
```
Given the root of a binary tree, return the inorder traversal of its nodes' values.
```

給定一棵 binary tree's root，將 inorder traversal 的結果存至一個 vector 並回傳。

Example
```
Input: root = [1,null,2,3]
    1
     \
      2
     /
    3
Output: [1,3,2]
```
## .cpp
### Version 1
注意:
- inorder traversal 是左中右
- 輸入的可能是空樹

多寫一個函數 traversal() 給主函數 inorderTraversal1() 呼叫，其中 traversal() 會利用遞迴的方式去做 inorder traversa，並在遞迴的過程中 maintain 原本的 result vector

這個作法的分析如下 (其中 n 是樹中節點總數)
- 時間複雜度: O(n)，因為每個節點都會被訪問一次。
- 空間複雜度: O(h+n)
    - O(h) 來自遞迴堆疊的深度，等同於樹高。
    - O(n) 來自 result vector 的大小
### Version 2
第二個作法比較沒那麼直觀，是直接利用主函數 inorderTraversal2() 作遞迴，而不需要另外撰寫 traversal() 函數來呼叫的方法。這個作法重要的一點是，因為每次遞迴呼叫回傳的是 vector，因此要記得去回收左右子樹的 result vector 到原本的 result vector 中。

這個作法的分析如下 (其中 n 是樹中節點總數)
- 時間複雜度: O(n^2)
    - 每個節點都會被訪問一次，此部分的時間複雜度是 O(n)
    - 每次呼叫遞迴函數都會將左右子樹的 result vector 合併到原本的 result vector 中，這個操作的時間複雜度取決於樹的平衡狀況，最壞情況可能是 O(n^2)
- 空間複雜度: O(h+n)
    - O(h) 來自遞迴堆疊的深度，等同於樹高。
    - O(n) 來自 result vector 的大小
        > 雖然每次遞迴呼叫都會涉及到新向量的創建和向量元素的合併，但這些向量在它們的作用域結束後就會被釋放（即當遞迴調用返回後，局部向量就不再存在）。因此，同一時間內實際占用的額外空間並不會累加所有遞迴層的向量空間。
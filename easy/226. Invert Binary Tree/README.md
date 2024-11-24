# [226. Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/description/)
## Introduction
給定指向一個二元樹的根節點的指標，反轉該二元樹，並回傳根節點的指標。

```
Input:
        4
      /   \
     2     7
    / \   / \
   1   3 6   9

Output:
        4
      /   \
     7     2
    / \   / \
   9   6 3   1
```
## .cpp
**< Description >**  

遞迴解，想法為：整棵樹要被反轉，那麼每個子樹也要被反轉。  
因此換句話說，等 root 的左右子樹皆反轉完成後，將左右子指標指向的東西調換即可。

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)
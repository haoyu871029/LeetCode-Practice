## 108. Convert Sorted Array to Binary Search Tree
[leetcode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/)

根據一個預排序過(ascending order)的整數陣列建立一棵 height-balanced binary search tree

Example
- Input: nums = [-10,-3,0,5,9]
- Output: [0,-3,5,-10,null,null,9] or [0,-10,5,null,-3,null,9] ... (還有其他可能)
```
         0
        / \
     -10   5
        \   \
        -3   9
```
```
         0
        / \
      -3   5
      /     \
    -10      9
```
### .cpp
以中間值作為 root

以 nums = [-10,-3,0,5,9] 為例，遞迴過程如下：
- build(nums, 0, 4), mid = 2
    - build(nums, 0, 1), mid = 0
        - build(nums, 0, -1), return nullptr
        - build(nums, 1, 1), mid = 1
            - build(nums, 1, 0), return nullptr
            - build(nums, 2, 1), return nullptr
    - build(nums, 3, 4), mid = 3
        - build(nums, 3, 2), return nullptr
        - build(nums, 4, 4), mid = 4
            - build(nums, 4, 3), return nullptr
            - build(nums, 5, 4), return nullptr
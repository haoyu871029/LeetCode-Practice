## 118. Pascal's Triangle
[leetcode](https://leetcode.com/problems/pascals-triangle/description/)

給定一個整數 numRows，回傳帕斯卡三角形的前 numRows 列，帕斯卡三角形中的每一個數字都是其上方兩個數字的和，例如下面是一部分的帕斯卡三角形：

```
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
```

Example
- Input: numRows = 5
- Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
### .cpp
先將三角形中所有元素初始化為 1，再利用 DP 的方式去處理每列除了頭尾的 1 以外的中間元素值，這個作法的時間複雜度是 O(numRows^2)
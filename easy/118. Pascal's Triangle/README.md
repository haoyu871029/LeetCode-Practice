## 118. Pascal's Triangle
[leetcode](https://leetcode.com/problems/pascals-triangle/description/)
## Introduction
給定一個整數 numRows，回傳帕斯卡三角形的前 numRows 列，帕斯卡三角形中的每一個數字都是其上方兩個數字的和，例如下面是一部分的帕斯卡三角形：

```
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
```

```
Example

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```
## .cpp
**< Description >**
- **Initialization** 階段先初始化一個三角形（所有元素為 1），作為下個階段 DP 時的 base。可以注意到，一開始就以欲回傳的資料格式 (`vector<vector<int>>`) 去建立三角形
- **Processing** 階段透過一列一列的處理元素值來完成整個帕斯卡三角形

```
vector<vector<int>> Solution::generate(int numRows) {
     /* Initialization */
     for (int i=1; i<=numRows; i++){
        初始化三角形的第 i 列
     }
     /* Processing (DP) */
     for (int i=2; i<numRows; i++){
        透過 DP 去處理三角形的第 i 列
     }
}
```

**< Discussions >**
- 注意每個 for 迴圈的範圍
     >- `for (int i=1; i<=numRows; i++)`  
     因為共需要初始化 numRows 列
     >- `for (int i=2; i<numRows; i++)`  
     因為若視整個三角形為第 0 列到第 (numRows-1) 列，則前兩列 `[1]` 和 `[1,1]` 是不需要處理的，也就是第 0 列和第 1 列。
     >- `for (int j=1; j<=(n-2); j++)`  
     因為若視三角形中每列的元素為第 0 個到第 (n-1) 個，則頭尾的 1 是不需要處理的，也就是每列的第 0 個和第 (n-1) 個元素。

**< Analysis >**  
以下的 n 代表 numRows
- Time complexity: O(n^2)
    - O(n^2) for Initialization
    - O(n^2) for Processing
- Space complexity: O(n^2)
    - O(n^2) for `ans`
    - O(1) for 其他臨時變數
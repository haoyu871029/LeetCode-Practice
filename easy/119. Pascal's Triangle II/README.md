# 119. Pascal's Triangle II
[leetcode](https://leetcode.com/problems/pascals-triangle-ii/description/)
## Introduction
回傳帕斯卡三角形中第 i 列的內容，範例的帕斯卡三角形如下：

```
     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
```

```
Example

Input: rowIndex = 3
Output: [1,3,3,1]
```

其他線索或限制如下:
- xxx
- xxx
## .cpp
**< Description >**
(用和 118 類似的邏輯) 先初始化一個所有元素皆為 1 的帕斯卡三角形，建到指定列即可。接著透過 DP 完成每一列的元素值，最後回傳指定列。

```
vector<int> getRow(int rowIndex) {
    vector<vector<int>> tri; //欲處理的帕斯卡三角形
    for {
        //第 i 列
        tri.push_back(vector<int>(i+1, 1));
    }//完成三角形的初始化
    if (指定第 0 列或第 1 列){
        return tri[rowIndex]; //不須處理元素值，因此直接回傳該列內容。
    }
    for {
        //第 i 列
        for {
            //第 i 列的第 j 個元素
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }
    return tri[rowIndex]; //回傳指定列
}
```

**< Analysis >**
n 代表指定之 rowIndex
- Time complexity: O(n^2)
- Space complexity: O(n^2)
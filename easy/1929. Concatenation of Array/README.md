# 1929. Concatenation of Array
[leetcode](https://leetcode.com/problems/concatenation-of-array/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入一個 vector<int> ，將其複製一遍，串接並回傳。

```
Example

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
```
## .cpp
### Version 0
**< Description >**

由於 vector 的 insert 方法本來就可以用來合併兩個 vectors，因此我們直接透過 insert 方法來完成。

```
vector<int> getConcatenation(vector<int>& nums) {
    1. 宣告一個 vector "result" 作為 nums 的克隆
    2. 將 result 的所有資料插入到 result 的尾端，完成串接。
}
```

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)
### Version 1
**< Description >**

不使用 insert 的作法，每圈完成兩個元素。

```
vector<int> getConcatenation(vector<int>& nums) {
    1. 宣告一個大小為 nums 兩倍的 vector "result"
    2. 利用一個 for 迴圈，每圈完成 result[i] 與 result[i+n] 兩個元素。
}
```

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)
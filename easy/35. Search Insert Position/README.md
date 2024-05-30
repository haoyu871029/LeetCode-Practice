# 35. Search Insert Position
## Description & Example
[leetcode](https://leetcode.com/problems/search-insert-position/description/)

Description
```
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
```
給定一個已排序的整數陣列 nums 和一個 target，若 target 在 nums 中存在，則回傳其 index，若不存在，則回傳 target 應該插入的位置。條件如下：
- 時間複雜度須為 O(logn)
- nums 為升冪排序，且元素不重複。
- 1 <= nums.length <= 10^4

Example
```
Input: nums = [1,3,5,6], target = 5
Output: 2
```
## .cpp
### Version 1
遍歷一次 nums，若找到 target 即回傳 i，若發現當前元素比 target 大，那該元素的 index 就是 target 應該存在的位置。target 大於目前 nums 中所有元素的情況也可以在做後迴圈結束後才回傳 n，如下所示，雖然可以少一個判斷，但就是需要完整遍歷一次 nums 才會回傳，而目前的寫法就可以在一開始就判斷，避免多餘的遍歷。

```cpp
int Solution::searchInsert1(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i=0; i<n; i++){
        if (nums[i]==target || nums[i]>target){ 
            return i;
        }
    }
    return n; //target 大於目前 nums 中所有元素
}
```

這個作法的分析如下
- 時間複雜度: O(n)，因為最差情況下要遍歷整個 nums
- 空間複雜度: O(1)
### Version 2
利用 Binary Search 的作法去找，在 target 存在於 nums 中的情況下很直觀，但當 target 不存在於 nums 中時，最會則要回傳 left，可以應付所有情況但比較難想到。

這個作法的分析如下
- 時間複雜度: O(logn)，因為 Binary Search 的作法。
- 空間複雜度: O(1)
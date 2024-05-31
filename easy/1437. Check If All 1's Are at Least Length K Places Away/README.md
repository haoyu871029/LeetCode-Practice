# 1437. Check If All 1's Are at Least Length K Places Away
## Description & Example
[leetcode](https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/)

Description
```
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
```
給定一個整數陣列 nums 代表一個二進制數字、一個整數 k 作為依據，去判斷 nums 中任兩個 1 之間是否都至少有 k 位存在。相關條件如下:
- nums 中只會有 0 或 1 (因為二進制數字)
- 1 <= nums.length <= 105
- 0 <= k <= nums.length

Example
```
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```
## .cpp
### Version 1
直覺上相鄰的 1 好判斷，但若是跳的組合好像要想一下，但其實如果相鄰符合，包在外面的也一定會符合，所以我們針對相鄰的組合一個一個去判斷就好。需要注意的是，根據測試過的測資，nums[0] 不一定是 1，所以要先找到起始 1 的位置，再開始作處理。

這個作法的分析如下
- 時間複雜度: O(n)，前面找初始 1 位置所需的遍歷，和後面作處理時所需的遍歷，在最差情況下(回傳 true 的情況)剛好也是 nums 的長度。
- 空間複雜度:  O(1)
### Version 2
第二個作法在概念上和 Version 1 相同，但差異是不用先判斷起始 1 的位置才開始處理。

這個作法的分析如下
- 時間複雜度: O(n)
- 空間複雜度:  O(1)
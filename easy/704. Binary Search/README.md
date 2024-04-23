## 704. Binary Search
[leetcode](https://leetcode.com/problems/binary-search/description/)

給定一個已經透過遞增排序好的數組 nums，以及一個目標整數 target。目標是在 O(log n) 的時間複雜度內找出 target，若找到則回傳其 index，沒找到則回傳 -1

Example
- Input: nums = [-1,0,3,5,9,12], target = 9
- Output: 4
- Explanation: 9 exists in nums and its index is 4
### .cpp
利用 start, end, k 這三個變數，來模擬三個指針，在 nums 上找 target
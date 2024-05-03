## 217. Contains Duplicate
[leetcode](https://leetcode.com/problems/contains-duplicate/description/)

給定一個整數陣列，判斷其中是否存在重複數，是則回傳 true，否則回傳 false

Example
- Input: nums = [1,2,3,1]
- Output: true
### .cpp
- version 1
    > 先排序再遍歷 nums ，在當前元素等於上一個元素時回傳 true，若遍歷結束都沒有回傳則回傳 false，但這樣的寫法時間複雜度為 O(nlogn)
- version 2
    > 遍歷 nums，當某個元素被判斷在 unordered_map 找得到，就回傳 true，否則將元素作為 key 存入 unordered_map，若遍歷結束都沒有回傳則回傳 false，這樣的寫法時間複雜度為 O(n)

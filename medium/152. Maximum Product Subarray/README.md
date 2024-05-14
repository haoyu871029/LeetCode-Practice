## 152. Maximum Product Subarray
[leetcode](https://leetcode.com/problems/maximum-product-subarray/description/)

給定一個整數陣列 nums，找出乘積最大的子陣列，並回傳該乘積。

Example
- Input: nums = [2,3,-2,4]
- Output: 6
- Explanation: [2,3] has the largest product 6.
### .cpp
#### Version 1
使用兩次遍歷來找到子陣列最大乘積。需要第二次遍歷是為了應付 nums 中有奇數個負數的情況，例如 [-1, -2, -3]，第一次遍歷找到的最大乘積為 2，但是第二次遍歷會找到最大乘積為 6

這個方法的時間複雜度為 O(n)
#### Version 2
只需遍歷一次的作法，多看一些測資的 cout 結果應該能講得更好。

notes: max() 一次最多只能比較兩個數

這個做法的時間複雜度也是 O(n)，但測試結果明顯較 Version 1 快。
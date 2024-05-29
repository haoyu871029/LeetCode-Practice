# 326. Power of Three
## Description & Example
[leetcode](https://leetcode.com/problems/power-of-three/description/)

Description
```
Given an integer n, return true if it is a power of three. Otherwise, return false.
```
給定一個整數 n，回傳其是否為 3 的次方。

Example
```
Input: n = 27
Output: true
Explanation: 27 = 3^3
```
## .cpp
### Version 1
Version 1 是遞迴的作法，其中 n%3==0 在檢查餘數，遞迴呼叫 isPowerOfThree(n/3) 則在檢查商數是否也是 3 的次方。

這個作法的分析如下
- 時間複雜度: O(logn)
- 空間複雜度: O(logn)，代表遞迴的深度。
### Version 1
利用迴圈去處理，若 n 是 3 的次方，在除 3 的過程中，一方面餘數會保持為 0 (除了最後一次)，一方面除到最後商數一定是 1

這個作法的分析如下
- 時間複雜度: O(logn)
- 空間複雜度: O(1)
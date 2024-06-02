# 191. Number of 1 Bits
## Description & Example
[leetcode](https://leetcode.com/problems/number-of-1-bits/description/)

Description
```
Write a function that takes the binary representation of a positive integer 
and returns the number of set bits it has (also known as the Hamming weight).
```
給定一個正整數，回傳其二進制表示中有多少個 1 (set bits/Hamming weight)

Example
```
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.
```
## .cpp
### Version 1
每次先測試除以 2 的餘數結果，若 (n%2 == 1)，代表此數二進制表示的最後一位會是 1，並記錄到 num 中。不論 n%2 的結果為何，處理後都要將 n 向右移一位，相當於執行 n/=2，並進行下一圈的迴圈，直到 n 為 0 為止。

這邊的 (n >>= 1) 可以用 (n /= 2) 取代，但是效能上會比較差，因為 (n >>= 1) 是直接對 n 進行位元運算，而 (n /= 2) 是對 n 進行除法運算。在底層，計算機處理位元運算通常比算術運算更快，右移運算符直接對位元進行操作，因此可以提高程式的執行效率，尤其在需要大量二進制操作的情況下。

這個作法的分析如下
- 時間複雜度: O(1)，因為題目的限制是 (1 <= n <= 2^31 - 1)，所以迴圈最多只會執行 32 次
- 空間複雜度: O(1)，只需要一個變數 num 來記錄 1 的個數

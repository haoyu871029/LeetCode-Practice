# 190. Reverse Bits
## Description & Example
[leetcode](https://leetcode.com/problems/reverse-bits/)

Description
```
Reverse bits of a given 32 bits unsigned integer.
```
給定一個 uint32_t type 的數字 n，將 n 的二進位表示法反轉後回傳。

Example
```
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: 
The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
so return 964176192 which its binary representation is 00111001011110000010100101000000.
```
## .cpp
```
每次利用 (n%2) 取得最右邊的 bit，將其左移正確的次數，再加到 result 上。
ex. n = 10011 ->19 (以 5-bit 來舉例)
n % 2 = 1, 代表最右邊的 bit 是 1
1 << (31-0), 代表將 1 左移 31 次
因此 x += (n%2) << (31-d) 是 00000 += 10000
第一圈結束後 x = 10000, n = 01001 (因為 n 也右移了一位)
```

這個作法的分析如下 (其中 n 是)
- 時間複雜度: O(1)，因為 n 是 32 bits，所以迴圈只會執行 32 次。
- 空間複雜度: O(1)，因為只使用了常數空間。

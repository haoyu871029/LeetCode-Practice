# 67. Add Binary
## Description & Example
[leetcode](https://leetcode.com/problems/add-binary/description/)

Description
```
Given two binary strings a and b, return their sum as a binary string.
```
給定代表兩個二進位數字的字串 a 和 b，將它們的相加結果存在一字串並回傳。

Example
```
Input: a = "1010", b = "1011"
Output: "10101"
```
## .cpp
### Version 1
較暴力的作法，先將幫位數少者補 0，接著利用一個 for loop，每圈針對每一位可能的計算情況，個別去判斷並做處理。過程中純粹是判斷並將對應的結果寫入，沒有利用額外的運算方式。

這個作法的分析如下 (其中 n 代表較長的字串長度)
- 時間複雜度: O(n)
    - 補零階段，若 a, b 兩字串長度相差懸殊，補零次數可能會接近 n 
    - 主處理時，for loop 執行次數為 n 次
- 空間複雜度: O(n)
    - 補零階段，若 a, b 兩字串長度相差懸殊，補零所需的額外空間為 O(n)
    - 主處理時，ans string 的長度最多為 n+1

### Version 2
先利用一個 while loop 去處理。每一位的計算都先將 carry, a[i], b[j] 三數相加，再利用 % 運算得到當前位數的值，並用 / 運算去得到給下一位的進位值，注意每一位處理前要將 value 歸零。while loop 處理完畢後，再將 ans string 反轉即可得到答案，這個作法在寫法上較 Version 1 來的精簡。

這個作法的分析如下 (其中 n 代表較長的字串長度)
- 時間複雜度: O(n)，迴圈執行次數最多是 n+1
- 空間複雜度: O(n)，因為 ans string 的長度最多為 n+1

while loop body 也可以直接用 carry 做處理而不需要 value 的寫法:
```cpp
    while (i>=0 || j>=0 || carry) {
        if (i >= 0){
            carry += (a[i--] - '0');
        }
        if (j >= 0){
            carry += (b[j--] - '0');
        }
        ans += (carry%2 + '0');
        carry /= 2;
    }
```
# 8. String to Integer (atoi)
[leetcode](https://leetcode.com/problems/string-to-integer-atoi/description/)
## Introduction
將一個字串轉換成 32-bit 有號整數，處理原則如下:
- 接受開頭有任意數量的空白
    > ex. " -42" -> -42
- 接受正負號
    > ex. "-42" -> -42
- 接受 leading zero
    > ex. "042" -> 42
- 若數字超出 32-bit 整數範圍 [-2^31, 2^31-1]，則回傳 INT_MAX (2^31-1) 或 INT_MIN (-2^31)
    > ex. "91283472332" -> 2147483647
- 若字串為空，或開頭為非數字，則回傳 0      
    > ex. "" -> 0, "words and 987" -> 0
- 只認連續數字      
    > ex. "1337c0d3" -> 1337

其他線索或限制如下:
- 字串中的默認順序會是 (I. 空白-正負號-起始零)-(II. 數字字串-非數字字串)
## .cpp
**< Description >**
```
int myAtoi(string s) {
    /* Processing for I. */
    判斷正負號，並找到 II. 在字串中開始的位置。

    /* Processing for II. */
    首先確定數字字串在整個字串中的範圍(頭尾位置)，再根據一些判斷處理可提前結束的情況，例如不存在數字字串或是溢位發生。

    /* Convertion */
    處理那些不需提前結束的情況，將數字字串部分轉換成數字並回傳。
}
```

**< Discussions >**
1. 這個版本的 `myAtoi()` 和原本 C++ 支援的 `stoi()` 差別為何？
    >- `stoi()` 執行成功時返回轉換的整數，執行失敗時拋出異常。`myAtoi()` 的執行則不會拋出異常，一定會返回一個整數值，例如當遇到無效輸入或超出範圍時，會返回 0、`INT_MAX` 或 `INT_MIN`
    >- 這個版本的 `myAtoi()` 最後還是會用到 `stoi()`，因此可以說是幫 `stoi()` 多處理了那些會拋出異常的情況。
2. 用到的函數
    >- `INT_MIN` 和 `INT_MAX` 分別代表 32-bit 有號整數的最小值和最大值，也就是 -2,147,483,648（即 -2^31）和 2,147,483,647（即 2^31 - 1） `<climits>`
    >- `isdigit()` 用於判斷一個字元是否為數字（即 '0' 到 '9' 之間的字元） `<cctype>`
    >- `substr(x,y)` 用於提取從字串中第 x 位開始長度為 y 的一段子字串 `<string>`

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(1)
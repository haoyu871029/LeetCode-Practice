## 1295. Find Numbers with Even Number of Digits
- [leetcode](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/)
- [chatgpt](https://chat.openai.com/share/e3531fbf-3a3f-4a93-b07f-5efec4565794)

給一個數字集合，找出其中位數為偶數的數字有幾個。

Example
- input: nums = [12,345,2,6,7896]
- output: 2
    > because 12 and 7896 have even number of digits.
### .cpp
每個數字利用 /10 的方式去計算位數
### .py
- version 1 和 .cpp 做法相同
- version 2 使用 list comprehension 的做法
### .c
和 1295.cpp 做法相同
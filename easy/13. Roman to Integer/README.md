## 13. Roman to Integer
- [leetcode](https://leetcode.com/problems/roman-to-integer/)
- [online converter](https://miniwebtool.com/zh-tw/roman-numerals-converter/?number=349)
- [chatgpt](https://chat.openai.com/share/ca2cb5c5-dd73-41b5-846d-641c4ecb4592)

Given a roman numeral, convert it to an integer.

Example
- Input: "III"
- Output: 3
### .cpp
- 先利用一個 map 去整理好羅馬數字與數字的對應關係
- 遍歷一次 s，若目前數字比下一個數字小，則用減的，否則用加的。
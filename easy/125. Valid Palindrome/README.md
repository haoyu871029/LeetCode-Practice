## 125. Valid Palindrome
[leetcode](https://leetcode.com/problems/valid-palindrome/description/)

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

給定一個字串 s，判斷其是否為一個 "Palindrome" (回文)。所謂回文是指，將字串中所有大寫字母轉換小寫，並移除所有 non-alphanumeric characters (字母和數字以外的字元) 後，字串正反讀取都相同。

Example
- Input: s = "A man, a plan, a canal: Panama"
- Output: true
- Explanation: "amanaplanacanalpanama" is a palindrome.
### .cpp
#### Version 1
先對 s 做預處理，只將 alphanumeric characters 填入新字串，並處理大小字母轉小寫。接著才利用一個 for loop 去檢查新字串是否為回文。但這個作法除了需要先對字串遍歷一遍來預處理外，還需要去計算欲比較的兩個字元的 index （不過如果用 while loop 並參考 Version 2 的 start 和 end 作法的話，應該就不用特別想 index 了）

這個作法分析如下:
- 時間複雜度為 O(n)，而且是遍歷兩次，第一次是 n，第二次是 n/2
- 空間複雜度為 O(n)，也就是用來放預處理結果的新字串。

#### Version 2
透過一個 while loop，利用 start 與 end 這兩個變數做到同時從頭往後掃以及由後往前掃，並檢查 s[start] 和 s[end] 是否相同，需要先經過一些小處理或判斷，像是確認兩者都是 alphanumeric character，還有要將大寫轉小寫。

這個作法分析如下:
- 時間複雜度為 O(n)，只需遍歷一次。
- 空間複雜度為 O(1)，只需要 start 和 end 兩個額外變數。
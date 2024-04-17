## 38. Count and Say
- [leetcode](https://leetcode.com/problems/count-and-say/)
- [chatgpt]()

回傳 countAndSay(n) 的結果，countAndSay(n) 的結果是針對 countAndSay(n-1) 結果的處理。

Example
- Input: n = 4
- Output: "1211"
- Explanation:
    > countAndSay(1) = "1"
    > countAndSay(2) = say "1" = one 1 = "11"
    > countAndSay(3) = say "11" = two 1's = "21"
    > countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
### .cpp
採用遞迴的方式，遍歷 countAndSay(n-1) 的結果來建立 countAndSay(n) 的結果。
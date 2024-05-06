## 290. Word Pattern
[letcode](https://leetcode.com/problems/word-pattern/description/)

給定一個 pattern string 和一個 s string，判斷 s string 是否符合。

Example 1
- Input: pattern = "abba", s = "dog cat cat dog"
- Output: true

Example 2
- Input: pattern = "aaaa", s = "dog cat cat dog"
- Output: false

Example 3
- Input: pattern = "e", s = "eukera"
- Output: true
### .cpp
#### Version 1
這個寫法只在「字母出現順序和單字出現順序ㄧ致時」會是對的，也就是第一個出現的單字對應到 'a'，第二個出現的單字對應到 'b'，以此類推。但本題沒有這個前提，Example 3 就是一個例子，所以這個寫法不會過。

1. 先將 s 轉換成 s's pattern，也就是將 s 的情況用一個 s_pattern string 來表示，比方說若 s = "dog cat cat dog"，s_pattern 就會是 "abba"
2. 將 check 和 pattern 作比較，相同代表  s 符合 pattern，不同則不符合。
#### Version 2
1. 建立兩個 map，一個用來記錄 pattern 中每個字母的最後出現位置，另一個用來記錄 s 中每個單字的最後出現位置，核心想法是「彼此對應的單字與字母，每次對到時各自的最後出現位置應該要一樣」。
2. 接下來同時遍歷 pattern 和 s (遍歷 s 為主)，兩種情況下會提前結束返回 false，一是目前讀取的單字數已經超過 pattern 的字母數，二是透過發現兩者的最後出現位置相異來辨識出彼此並非對應關係。若非這兩種情況，代表目前讀取的單字數還沒超過 pattern 的字母數，且兩者的最後出現位置相同，因此更新兩者的最後出現位置後就可以再繼續往下遍歷。
3. 若遍歷結束後，i==n 就代表單字數和 pattern 中字母數相同，且沒有提前結束代表 s 符合 pattern。而若 i!=n，則代表 s 遍歷完了都還符合 pattern 前段，但 pattern 還有後段。

(應該也可以用累積出現次數去判斷)
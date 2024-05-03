## 242. Valid Anagram
[leetcode](https://leetcode.com/problems/valid-anagram/description/)

所謂的 anagram 指的是同樣的字母組合重新排列。給定兩個字串 s 和 t，判斷 t 是否為 s 的 anagram

Example
- Input: s = "anagram", t = "nagaram"
- Output: true
### .cpp
- version 1
    > 兩個字串都先 sort 好，再去比較兩個字串是否相同，這樣的做法時間複雜度為 O(nlogn)
- version 2
    > 用一個大小為 26 的 vector 同時去遍歷 s 和 t，並考慮 s 和 t 中各字母的出現情況，若 t 是 s 的 anagram，最後 vector 中每個元素都應該為 0，這樣的做法時間複雜度為 O(n)
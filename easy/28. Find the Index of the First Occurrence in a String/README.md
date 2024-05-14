## 28. Find the Index of the First Occurrence in a String
[leetcode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/)

給定兩個字串 needle 和 haystack，若 needle 是 haystack 的子字串，則回傳 needle 在 haystack 中第一次出現的位置，否則回傳 -1。

Example 1
- Input: haystack = "sadbutsad", needle = "sad"
- Output: 0
- Explanation: 
    > "sad" occurs at index 0 and 6. 
    > The first occurrence is at index 0, so we return 0.

Example 2
- Input: haystack = "leetcode", needle = "leeto"
- Output: -1
- Explanation: 
    > "leeto" did not occur in "leetcode", so we return -1.
### .cpp
#### Version 1 
想法是，從 haystack 中找出所有開頭和 needle 相同的子字串(儲存他們開頭的 index)，並比較這些字串是否和 needle 相同，並返回第一個相同的字串的開頭 index
1. 利用一個迴圈去遍歷 haystack，找出所有與 needle 的第一個字母相同的字母，並將他們的 index 存入 record vector 中。
2. 利用一個迴圈，每次從剛剛存的那些 index 作為起點建立一個和 needle ㄧ樣長的字串 test，並比對 test 和 needle 是否相同。

但這個做法的時間複雜度是 O(mn)
#### Version 2
直接利用 string's find method 來找出第一個子字串在 haystack 中的位置，若找不到會返回 -1。因此這個做法的時間複雜度就是 string's find method 的時間複雜度，通常會接近 O(m+n)

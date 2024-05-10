## 344. Reverse String
[leetcode](https://leetcode.com/problems/reverse-string/description/)

給定一個以 vector<char> 表示的字串 s，將其反轉，並有以下限制：
- modifying the input array in-place
- O(1) extra memory

Example
- Input: s = ["h","e","l","l","o"]
- Output: ["o","l","l","e","h"]
### .cpp
#### Version 1
利用對調的方式，將第一個元素與最後一個元素對調，第二個元素與倒數第二個元素對調，以此類推，直到中間元素，即可完成反轉。這個做法的時間複雜度是 O(n/2) = O(n)，空間複雜度是 O(1)
#### Version 2
直接使用 <algorithm> 中的 reverse 函數去反轉 vector，這個函數的時間複雜度是 O(n)，空間複雜度是 O(1)
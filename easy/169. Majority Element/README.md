## 169. Majority Element
[leetcode](https://leetcode.com/problems/majority-element/description/)

給定一個大小為 n 的整數陣列 nums，回傳 nums 中的 majority element（假設 majority element 一定存在於 nums 中）。所謂 majority element 就是指出現次數超過 ⌊n/2⌋ 次的元素。

Example
- Input: nums = [2,2,1,1,1,2,2]
- Output: 2
- Explanation: 2 出現 4 次，超過 ⌊7/2⌋ = 3，故為 majority element。
### .cpp
#### Version 1
用一個 map 去紀錄 nums 中每個數字的出現次數，再遍歷 map，一找到出現次數超過 ⌊n/2⌋ 次的數字就回傳該數字。

這個作法的分析如下:
- 時間複雜度: O(n)，且要遍歷兩次 n
- 空間複雜度: O(n)，因為需要用一個 map 去紀錄每個數字的出現次數。
#### Version 2
使用 Boyer-Moore Voting Algorithm，其核心思想是對抗消除不同的元素，以找到可能的候選者，這種算法的正確性基於一個假設：數組中確實存在一個多數元素。當一個元素的數量超過總數的一半時，在對抗過程中，即使所有其他非多數元素互相抵消，最終剩下的必然是這個多數元素。因此，此算法在保證有多數元素存在的情況下非常高效。

利用兩個變數來處理，count 代表目前領先者的領先幅度，leader 代表目前的領先者，當領先幅度歸零，代表領先者要換人。但這個作法只在 majority element 存在的情況下才會正確，比方說若 nums = {2,1,3,1,4}，這個作法會回傳 4，但 4 並不是 majority element

這個作法的分析如下:
- 時間複雜度: O(n)，只需要遍歷一次 n
- 空間複雜度: O(1)，只有 leader 和 count 這兩個主要變數。
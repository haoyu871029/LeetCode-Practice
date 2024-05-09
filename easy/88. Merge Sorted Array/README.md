## 88. Merge Sorted Array
[leetcode](https://leetcode.com/problems/merge-sorted-array/description/)

給定兩個整數陣列 nums1 和 nums2 (they are sorted in non-decreasing order)，以及兩個整數 m 和 n，分別代表 nums1 和 nums2 中的數字個數。目標是將 nums1 和 nums2 合併成一個陣列 (also sorted in non-decreasing order)，但希望這個合併陣列是直接存放於 nums1 中，因此 nums1 的大小原本就是 m+n，原始 nums1 中前 m 個元素是要被合併的 m 個數字，後 n 個元素則是 0

Example 1
- Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
- Output: [1,2,2,3,5,6]

Example 2
- Input: nums1 = [0], m = 0, nums2 = [1], n = 1
- Output: [1]
### .cpp
#### Version 1
將 nums2 的元素放入 nums1 的後 n 個位，再對 nums1 進行排序，這個做法的時間複雜度為 O((m+n)log(m+n))
#### Version 2
想法是，從 nums1 尾巴開始放，每次從 nums1 和 nums2 選人放進來。
- 如果最後 (n>0)，代表 num1 的元素都被選上了，剩下的 nums1 前段位置就是用來放 nums2 剩下沒被選上的元素，再透過一個迴圈來處理。
- 如果最後 (m>0)，代表 nums2 的元素都被選上了，剩下的 nums1 前段位置就是用來放 nums1 剩下沒被選上的元素，又因為已經預排序過的關係，這些元素已經在正確的位置上了，所以不用再處理。

簡單來說，從尾巴開始掃，從尾巴開始放，這個做法的時間複雜度為 O(m+n)

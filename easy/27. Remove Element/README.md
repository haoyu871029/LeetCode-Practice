## 27. Remove Element
[leetcode](https://leetcode.com/problems/remove-element/description/)

給定一個整數陣列 nums 和一個整數 val，假設 nums 中不等於 val 的元素數量為 k，將 nums 中所有的 val 刪除，並將不等於 val 的這 k 個數推到 nums 前面，並回傳 k

Example
- Input: nums = [0,1,2,2,3,0,4,2], val = 2
- Output: 5, nums = [0,1,4,0,3,_,_,_]
### .cpp
用一個變數 curr_index 來記錄目前要放入非 value 元素的位置，遍歷 nums 的過程中，只要碰到非 value 元素，就將其放入 nums[curr_index]，同時把 curr_index 和 k 都加一。遍歷完成後，nums 中前 k 個元素都是非 value 的元素，後面的元素因為不檢查所以不處理，回傳 k 即可。
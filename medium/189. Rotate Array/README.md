## 189. Rotate Array
[leetcode](https://leetcode.com/problems/rotate-array/description/)

給定一個整數陣列 nums 和一個非負整數 k，將 nums 進行右移 k 次，數字在陣列中是右出左進。

Example
- Input: nums = [1,2,3,4,5,6,7], k = 3
- Output: [5,6,7,1,2,3,4]
- Explanation:
    - rotate 1 steps to the right: [7,1,2,3,4,5,6]
    - rotate 2 steps to the right: [6,7,1,2,3,4,5]
    - rotate 3 steps to the right: [5,6,7,1,2,3,4]
### .cpp
#### Version 1: stack 法
要注意的是要改動原本的 nums。先將 nums 元素由右至左全部推入一個 stack，接著按照 k 決定怎麼從 stack 中拿出元素並放入 nums 

時間複雜度和額外空間使用皆為 O(n)
#### Version 2
先將 nums 複製一份到 numcopy 作為等等的參考，接著直接在遍歷的過程中去位移當前數字在 nums 中的位置。寫法筆記簡潔，但不是那麼直觀。

時間複雜度和額外空間使用皆為 O(n)
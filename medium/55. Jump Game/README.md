## 55. Jump Game
- [leetcode](https://leetcode.com/problems/jump-game/)

給定一個整數陣列 nums，其中每個元素值代表可以從該位置往後跳多遠。若從 index 0 開始，判斷是否有辦法抵達最後一個 index

Example
- Input: nums = [2,3,1,1,4]
- Output: true
- Explanation: 
    > Jump 1 step from index 0 to 1, then 3 steps to the last index.
### .cpp
遍歷 nums，並在過程中利用一個變數去存「目前最遠可以跳到的位置」，以下兩種情況會提前結束：
1. 若 (i > maxReach)，代表前面不管怎麼跳，都到不了現在這裡，所以就算 index i 以後有辦法跳到 last index 也沒用，因此需回傳 false，這也是唯一要回傳 false 的情況。
2. 若 (maxReach >= n-1)，代表提前確定可以飛到終點甚至超過，因此可以提前結束回傳 true，而不用繼續遍歷。
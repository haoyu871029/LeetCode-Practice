## 45. Jump Game II
- [leetcode](https://leetcode.com/problems/jump-game-ii/description/)
- [chatgpt](https://chat.openai.com/share/d53ce949-58c7-4d9b-a899-1c9df4d4c81d)

給定一個整數陣列 nums，其中每個元素值代表可以從該位置往後跳多遠，假設所有測資都可以跳到終點，請回傳跳到終點最少幾步可完成，給定條件如下：
- 0 <= j <= nums[i] 
    > 意思是可以選擇跳 0~nums[i] 步
- i + j < n
    > 意思是不會跳超過終點

Example
- Input: nums = [2,3,1,1,4]
- Output: 2
- Explanation: 
    > The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
### .cpp

目前先寫在註解中
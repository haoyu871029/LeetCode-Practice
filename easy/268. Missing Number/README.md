## 268. Missing Number
- [leetcode](https://leetcode.com/problems/missing-number/description/)
- [chatgpt](https://chat.openai.com/share/ed20e5cb-529c-4874-8248-5adbc11b1365)

給定一個包含 n 個不同數字的數組 nums，其中數字的範圍是 [0, n]，找出唯一缺失的那個數字。

Example
- Input: nums = [3,0,1]
- Output: 2
- Explanation
    > n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
### .cpp
#### Version 1: 預排序法
先對 nums 作排序，接著遍歷 nums 並用 index i 作比對，可以在兩種情況下找到 missing number：
1. 遍歷時，當 i 沒對到 nums[i]，代表 i 不在 nums 中，i 即為 missing number
2. 遍歷完 nums 還沒找到，代表 0~(n-1) 都在 nums 中，因此 n 即為 missing number
#### Version 2: map 法
先將 nums 中的數字都存進 map 作為 key，接著就看 0~n 哪個數字沒辦法在 map 中找到，該數字即為 missing number，因此 map 各 item 的 value 就不重要了。
#### Version 3: 過濾法
利用 XOR 運算的交換律和結合律，舉例如下：
- loop 1：  x = A ⊕ C ⊕ D
- loop 2：  x ⊕ (A ⊕ B ⊕ C ⊕ D)
    - = (A ⊕ C ⊕ D) ⊕ (A ⊕ B ⊕ C ⊕ D)
    - = (A⊕A) ⊕ (C⊕C) ⊕ (D⊕D) ⊕ B
    - = 0 ⊕ 0 ⊕ 0 ⊕ B
    - = B

因此可以過濾出 missing number
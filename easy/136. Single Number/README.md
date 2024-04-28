## 136. Single Number
- [leetcode](https://leetcode.com/problems/single-number/description/)
- [chatgpt](https://chat.openai.com/share/29aa4815-bc3d-416e-b287-047b2aef57c2)

給定一個非空整數陣列 nums，除了一個元素會只出現一次外，其餘每個元素都出現兩次，找出這個只出現一次的元素，有以下要求：
- linear runtime complexity
- use only constant extra space

Example
- Input: nums = [4,1,2,1,2]
- Output: 4
### .cpp
原本有想到兩種做法
1. (沒實作) 先用 map 記錄每個數字的出現次數，再遍歷一次 map，回傳 value 是 1 的 key，這樣的時間複雜度會是 O(n)，但會用到 O(n) 的額外空間。
2. (singleNumber1) 先排序，ex. 1,1,2,2,4,5,5,6,6 return 4，雖然 submit 會通過，但這樣時間複雜度是 O(nlogn)，額外空間使用因為 sort() 的使用因此是 O(logn)
3. (singleNumber2) 利用 XOR 運算的特性，所以將所有數字 XOR 一次，最後的運算結果就是只出現一次的那個數字。這樣的時間複雜度是 O(n)，額外空間使用是 O(1)

XOR 運算特性：
- (反身性) 任何數與自己進行 XOR 運算的結果為 0
    > a ⊕ a = 0
- 任何數與 0 進行 XOR 運算的結果為該數本身
    > a ⊕ 0 = a
- (交換律) XOR 運算可以在任何順序下進行，結果都相同。
    > a ⊕ b = b ⊕ a
- (結合律) XOR 運算可以被分組在任何方式，結果都相同。
    > ( a ⊕ b ) ⊕ c = a ⊕ ( b ⊕ c )
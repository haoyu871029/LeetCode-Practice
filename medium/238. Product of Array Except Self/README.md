## 238. Product of Array Except Self
[leetcode](https://leetcode.com/problems/product-of-array-except-self/description/)

給定一個整數陣列 nums，回傳一個整數陣列 ans，其中 ans[i] 是 nums 中除了 nums[i] 之外所有元素的乘積。限制是要在 O(n) 時間複雜度內完成，且不能使用除法運算。

Example
- Input: nums = [1,2,3,4]
- Output: [24,12,8,6]
- Explanation: 
    > - ans[0] = 2*3*4 = 24
    > - ans[1] = 1*3*4 = 12
    > - ans[2] = 1*2*4 = 8
    > - ans[3] = 1*2*3 = 6
### .cpp
這個解法分為兩部分來完成
1. 先利用 partial_sum() 來計算前綴連乘與後綴連乘
2. 每個 ans[i] 原則上是 pre[i-1] * suf[i+1] 的結果，但要考慮邊界元素的情況。

以 nums = {1,2,3,4} 為例：
- pre 存放前綴連乘
    - pre[0] = 1
    - pre[1] = 1*2
    - pre[2] = 1*2*3
    - pre[3] = 1*2*3*4
- suf 存放後綴連乘
    - suf[3] = 4
    - suf[2] = 4*3
    - suf[1] = 4*3*2
    - suf[0] = 4*3*2*1

for loop 內的程式碼可以簡化為以下
```cpp
int ans[i] = (i==0 ? 1 : pre[i-1]) * (i==nums.size()-1 ? 1 : suf[i+1]);
```
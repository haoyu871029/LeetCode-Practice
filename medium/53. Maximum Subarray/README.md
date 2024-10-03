# [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/solutions/1595195/c-python-7-simple-solutions-w-explanation-brute-force-dp-kadane-divide-conquer/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入一個整數數列 `vector<int>& nums`，回傳可能的最大子數列和。

```
Example

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

其他線索或限制如下:
- 1 <= `nums.length` <= 10^5
- -10^4 <= `nums[i]` <= 10^4
## .cpp
**< Description >**

利用 `vector<int> dp0(n)` 和 `vector<int> dp1(n)` 這兩個陣列來實作 dp 解

`dp1[i]` 代表子數列在以 `nums[i]` 結尾的前提下，最大的子數列和。而 `dp1[i]` 只可能會是以下兩種情況之一：
- 子數列只有 `nums[i]`，，則該子數列和的最大值為 `nums[i]`
- 子數列不只有 `nums[i]`，則該數列必包含 `nums[i-1]`，因此這個子數列和的最大值為 `dp1[i-1] + nums[i]`

`dp0[i]` 代表從 nums[0] 到 nums[i] 的範圍內，可能的最大子數列和。而 `dp0[i]` 只可能會是以下兩種情況之一：
- 子數列中有 `nums[i]`，則該子數列和的最大值為 `dp1[i]`
- 子數列沒有 `nums[i]`，則該子數列和的最大值為 `dp0[i-1]`，即到前一個 index 為止找到的最大子陣列和。

而題目所求即為 `dp0[nums.size()-1]`

**< Analysis >**
- Time complexity: O(n)
- Space complexity: O(n)
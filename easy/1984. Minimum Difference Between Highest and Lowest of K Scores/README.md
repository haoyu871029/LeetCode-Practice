# [1984. Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
給定一個整數陣列 `vector<int>& nums`，代表學生的分數，以及一個整數 `int k` 代表欲選擇的學生數。回傳在任意選擇 k 的學生的情況下，這 k 個學生中最高分與最低分的可能最小差值。

```
Example

Input: nums = [9,4,1,7], k = 2
Output: 2
Explanation: 挑選 7 與 9，則最高分與最低分的差值為 2，是所有組合中最低的。
```

其他線索或限制如下:
- 1 <= k <= `nums.length` <= 1000
- 0 <= `nums[i]` <= 10^5
## .cpp
**< Description >**

- 基本的解題邏輯為，讓每個分數都作為某組中的最低分去試試看。而為了找到最小的差值，同組的最高分勢必會在該最低分的附近，因此會預先將 `nums` 排序。
- 在處理階段，遍歷一次 `nums`，每圈將 `nums[i]` 作為最低分，`nums[i], nums[i+1], ..., nums[i+k-1]` 會是同一組，而 `nums[i+k-1]-nums[i]` 便會是測試差值。

**< Analysis >**
- Time complexity: O(nlogn)
- Space complexity: O(1)
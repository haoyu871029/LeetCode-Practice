# [2215. Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
輸入兩個數列 `vector<int>& nums1` 與 `vector<int>& nums2`，回傳一 `vector<vector<int>> answer`，其中：
- `answer[0]` 收集了在 `nums1` 中存在，但 `nums2` 中沒有的數。
- `answer[1]` 收集了在 `nums2` 中存在，但 `nums1` 中沒有的數。

```
Example

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
```

其他線索或限制如下:
- 1 <= nums1.length, nums2.length <= 1000
- -1000 <= nums1[i], nums2[i] <= 1000
## .cpp
**< Description >**

先將 `nums1` 與 `nums2` 分別轉換成 `unordered_set`，接著分別遍歷兩個 `unordered_set`，並在過程中利用 `find()` 完成 `vector<vector<int>> answer`。這邊利用了 `unordered_set` 基本操作的時間複雜度為 `O(1)`，且不會有重複元素的特性。

**< Discussions >**
- 使用 `unordered_set` 比 `unordered_map` 適合的原因 ?
    > 若使用 `unordered_map`，為了處理重複的數字，會需要在轉換的過程中去判斷數字是否已經存在，以 `nums1` 來說：
    > ```cpp
    >for (auto i :nums1){
    >    if (mp1.find(i) == mp1.end()){
    >        mp1[i] = 1;
    >    }
    >}
    >```

**< Analysis >**  
m = nums1.size(), n = nums2.size()
- Time complexity: O(m+n)
- Space complexity: O(m+n)
# 56. Merge Intervals
[leetcode](https://leetcode.com/problems/merge-intervals/description/)
## Description & Example
給定一個含有多個區間的 intervals vector，將有重疊部分的多個區間合併成一個，並回傳整理後的 result vector。其他線索或限制如下:
- intervals vector 不會是空的，至少會有一個區間存在。
- 合併有重疊的 intervals 即可，例如 [1,3] [4,5] 就不需要合併成 [1,5]

```
Example
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```
## .cpp
### Version 1
**Description**  
先將 vector intervals 中的每個 interval 轉成 pair，接著對 vector intervals 進行預排序。接著，遍歷一遍 vector intervals，過程中判斷重疊與不重疊的情況，看是要做合併還是提交。

```cpp
```

**Discussions**
1. 為什麼迴圈終止條件為 `i<p.size()-1` 而非 `i<p.size()` ?  
因為每一圈會使用到 `p[i+1]` 來判斷是否有重疊，因此迴圈只跑到倒數第二個元素，而最後一個 intervals 會在迴圈執行完後再做一次 push_back 加入。  
2. 為什麼在 pre-sorting 階段不直接對 vector intervals 做排序，而要先將每個 interval 轉換成 pair ?  
排序的簡便性與效率。`pair<int, int>` 在 C++ 中具有預定義的比較運算子，這意味著當你對 pair 進行排序時，會自動按照第一個元素（即 interval 的起始點）進行排序，如果第一個元素相同，則會按照第二個元素（即 interval 的結束點）排序。這種排序方式正好符合合併 interval 的需求。相較之下，雖然 `vector<int>` 也有定義好的比較運算子（會進行字典序比較），但在處理固定大小（兩個元素）的資料時，pair 的性能和記憶體使用會更有效率。  
**Analysis**
- 時間複雜度: O(nlogn)
    - O(nlogn) for pre-sorting
    - O(n) for traversing the vector
- 空間複雜度: O(n)
    - O(1) for p, f, s
    - O(n) for ans

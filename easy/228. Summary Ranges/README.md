## 228. Summary Ranges
## Description & Example
[leetcode](https://leetcode.com/problems/summary-ranges/)

Description
```
You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
```

給一個 sorted unique integer array (已排序且沒有重複元素) nums，試著利用最少的 range 數去把所有 combo 都列出來。
- 每個元素只屬於一個 range
- 沒有元素會屬於某個 range 但卻不在 nums 中

Example
```
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
```
## .cpp
### Version 1
直覺的想法是直接去遍歷 nums，當發現不連續時，就整理一個 range 到 result vector，但實作時有兩點需要注意:
- 要往前收斂的情況有二，一個是正常斷 combo 的時候，另一個是要去紀錄最後一段 combo 時。
- nums 可能會是空的、處理時可能會不小心有 overflow 的問題。

這個作法的分析如下
- 時間複雜度: O(n)，因為用 for loop 遍歷了 nums 一次。
- 空間複雜度: O(n)，來自 result vector 的大小。

原本因為覺得 for loop 中兩個 if body 寫的內容差不多，為了避免程式碼冗長，因此選擇先將一個 stopper 插入原始 nums array 以預設好最後一個斷 combo 的情況，寫法如下。這樣的寫法雖然比較簡潔，且在正常情況是正確的，但若遇到像 [-2147483648,-2147483647,2147483647] 這樣的測資時，stopper 的設定會發生 overflow (2147483647 已經是 INT_MAX)，導致後續的處理出現問題。
```cpp
int stopper = nums[n-1]+2;
nums.push_back(stopper);
for (int i=1; i<=n; i++){
    if (nums[i] != (nums[i-1]+1)){//正常斷 combo 的時候
        end = nums[i-1];
        if (head == end){
            result.push_back(to_string(head));
        }
        else{
            result.push_back(to_string(head)+"->"+to_string(end));
        }
        head = nums[i];
    }
}
return result;
```
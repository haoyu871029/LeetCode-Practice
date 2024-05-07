## 21. Merge Two Sorted Lists
[leetcode](https://leetcode.com/problems/merge-two-sorted-lists/description/)

給定兩個 sorted linked list (non-decreasing order)，目標是將這兩個 linked lists 合併成一個 sorted linked list，並回傳指向 result linked list's head 的指標。

Example
- Input: list1 = [1,2,4], list2 = [1,3,4]
- Output: [1,1,2,3,4,4]
### .cpp
#### Version 1
希望不更動 result, list1, list2 指向的原始位置，因此分別各用一個指標去遍歷每個 linked list
- temp 用來走訪 result linked list 以建構結果
- temp_1 用來走訪 list1
- temp_2 用來走訪 list2

實作思路為，在 list1 和 list2 都還有時才做主處理，所謂主處理就是比較當前 list1 和 list2 走訪到的值並將較小值創建一個 ListNode 給 result linked list 接下去，並根據實際情況看要如何移動 temp, temp_1, temp_2。主處理結束後，代表一定有一方已經走訪完了（應該不存在兩邊在主處理後都同時走訪完的情況），又因為 list1 和 list2 都是 sorted linked list，所以可以未走訪完的 linked list 的剩餘部分直接接到 result linked list 後面，最後回傳 result->next 即可，因為 result 原本指向的是一個 dummy node
#### Version 2
作法和 Version 1 差不多，但做了兩個小優化：
1. 因為題目有提示 "The number of nodes in both lists is in the range [0, 50]."，因此一開始可以判斷是否有 empty list 存在，若有則直接回傳另一個 list 即可。
2. 在建構 result linked list 的過程中，可以直接將 temp 指向 list1 或 list2 上的 node，而不用另外創建 new ListNode instance 來指。

測試的結果上 Version 2 比 Version 1 快，但差異不大。
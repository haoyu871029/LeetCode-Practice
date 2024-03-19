## 645. Set Mismatch
在具有 n 個數字的集合中(數字範圍為 1～n)，找出重複的數字和缺少的數字。

Example
- Input: nums = [1,2,2,4]
- Output: [2,3]
### .cpp
兩個版本概念上相同，先利用一個資料結構 ds 初始化 1～n 的狀態為 0，再遍歷 nums 更新 ds 中 1～n 的狀態，
最後再遍歷一次 ds，找到狀態為 2 或 0 分別代表重複的數字和缺少的數字，再將它們輸入 vector 並回傳。

- version 1: ds 用 vector 實作
- version 2: ds 用 map 實作

測試結果是 version 1 比 version 2 快，原因如下：

vector 在記憶體中是連續分配的，代表可以非常高效地被存取和遍歷。
而在 C++ 中，map 通常是用平衡樹（如紅黑樹）來實現的，使得元素的插入和查找時間複雜度為O(log n)，比 vector 的 O(1) 時間複雜度要慢。
在一些要跑 n 圈的 loop 中，因為 map 的存取時間複雜度是 O(log n)，所以整體的時間複雜度會高於 O(n)
### .c
和 .cpp version 1 做法相同，先記錄到 record 裡面，再遍歷 record 作檢查。

malloc（Memory Allocation）和 calloc（Contiguous Allocation）都是 C 語言中用於動態記憶體分配的函數，差異如下：

- malloc: 分配的記憶體不會被初始化，也就是說記憶體區塊中的初始值是未定義的，通常是該記憶體區域之前的任意數據。
- calloc: 分配的記憶體會被自動初始化為零，也就是說所有位元組都會被設置為0。
### .py
和 .cpp version 1 做法相同，先記錄到 record 裡面，再遍歷 record 作檢查。
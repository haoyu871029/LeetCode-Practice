# 121. Best Time to Buy and Sell Stock
## Description
[leetcode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

Description
```
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
```

給定一個整數陣列代表某支股票每一天的價格，請判斷該在哪一天買進、哪一天賣出可以得到最大獲利，並回傳該獲利值，若無法獲利則回傳 0

Example
```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: 在第 2 天買進，並在第 5 天賣出，可以得到最大獲利 6-1 = 5
```
## .cpp
注意到的點是，只有穩定在跌的股票不會有獲利，而第一個想到的暴力法是，去整理每一天買進分別可以獲得的最大獲利---O(n^2)，最後比較 n 個獲利值並將最大的獲利回傳---O(n)，但這樣的時間複雜度是 O(n^2)，空間複雜度是 O(n)，因此應該要去想，有沒有能在遍歷的同時去 maintain 最大獲利，以達到時間複雜度 O(n) 的作法。

這個作法的想法是，遍歷一次 prices，每天都去更新哪天買進其實最便宜，每天也去更新可能的最大獲利。這個作法可以同時處理沒有獲利的情況，因為在穩定跌的情況下，max_profit 每一天更新後都會是 0

這個作法的分析如下
- 時間複雜度: O(n)
- 空間複雜度: O(1)
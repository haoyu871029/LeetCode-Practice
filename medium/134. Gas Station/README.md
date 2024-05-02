## 134. Gas Station
- [leetcode](https://leetcode.com/problems/gas-station/description/)
- [chatgpt](https://chat.openai.com/share/808a54c3-9f72-4c46-8e19-8d1d8e27c9e6)

在一個圓形路線上有 n 個加油站，第 i 個加油站有 gas[i] 的油量。若有一輛車從第 i 個加油站到第 i+1 個加油站需要 cost[i] 的油量，起點是某一個加油站，且一開始車並沒有油。回傳一個可能的起點加油站，讓車子從該站開始能成功順時針繞一圈（假設該起點存在，則一定是唯一的），若這樣的起點不存在則回傳 -1。

Example
- Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
- Output: 3
### .cpp
#### Version 1
先過濾掉不可能的起點，接著每個可能的起點都去試試看。

但這個做法的缺點是，每個有效起點都會試，且每個起點都可能要繞完全部才確認是否可行，因此在後面一點的測資會發生 TLE 

時間複雜度: O(n^2^)
#### Version 2
關鍵在於，若第 i 站到第 j 站剩下的油量不足以到達第 j+1 站，那麼 i 到 j 之間的任何一站都不可能是起點。


時間複雜度: O(n)
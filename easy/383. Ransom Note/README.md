## 383. Ransom Note
- [leetcode](https://leetcode.com/problems/ransom-note/description/)
- [chatgpt](https://chat.openai.com/share/d5558f54-5acb-47cf-936a-361f716237db)

組成 magazine 的字母是否能組成 ransomNote

Example
- Input: ransomNote = "ad", magazine = "abcd"
- Output: true
- Explanation: "a" and "d" can be constructed from magazine.
### .cpp
- canConstruct1
    > 先建構一個 unordered_map 來計算 magazine 中每個字母的數量，並在遍歷 ransomNote 時用來消耗。兩種情況下會失敗收場：
    > 1. magazine 中沒有目前在找的 ransomNote 字母
    > 2. magazine 中的某個字母數量不夠
- canConstruct2
    > 先將 ransomNote 和 magazine 都排序一遍，接著同時遍歷 ransomNote 和 magazine。兩種情況下會失敗收場：
    > 1. magazine 掃完之前就確定裡面沒有目前在找的 ransomNote 中的字母
    > 2. magazine 掃完了但 ransomNote 還沒全部找完
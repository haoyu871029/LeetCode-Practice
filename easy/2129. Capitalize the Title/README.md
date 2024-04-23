## 2129. Capitalize the Title
輸入是一句英文句子，但每個單字大小寫是亂的，若單字長度 ≤2，則將該單字全部轉小寫，若單字長度 >2，則將該單字的第一個字母轉大寫，其餘轉小寫。

Example
- Input: "capiTalIze tHe titLe"
- Output: "Capitalize The Title"
### .cpp
另外創建一個 result string，遍歷 title string 一次取一個單字，並遍歷一次該單字做對應的處理，處理完連同一個空白格加入 result string，所有單字處理完後要去除最後的空白格。
- 從字串中取單字的做法: istringstream 搭配 while loop
- 英文字元轉大寫: toupper()
- 英文字元轉小寫: tolower()
- 去除字串最後的空白格: pop_back()
### .c
直接對 title 作更改。
不管怎樣先轉小寫，碰到 ' ' 或 '\0' 才回去將 ' ' 或 '\0' 之前的那個單字的第一個字母轉大寫。
count 用來記錄 ' ' 或 '\0' 之前的那個單字的字符數量
### .py
和 cpp 相同作法
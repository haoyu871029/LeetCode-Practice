## 819. Most Common Word
將一段句子中出現頻率最高的單字回傳，但要排除 banned 中的單字。

Example
- input: 
    - paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
    - banned = ["hit"]
- output: "ball"
### .cpp
1. 對 paragraph 作預處理
    > 遍歷 paragraph 中的字元，因為裡面只可能是標點符號、空白、字母，因此若字元為標點符號就轉為空白，若為字母則轉為小寫。
2. 對 banned 作預處理
    > 將 banned 中的元素從 vector 轉移到 unordered_set，為了提升之後的查找效率。
3. 記數的同時做判斷
    > 利用 istringstream 以空白分割 paragraph，針對每個單字去處理，處理流程為先計數，再判斷。
- 判斷是否為標點符號: ispunct()
- 將字元轉小寫: tolower()
### .py
作法與 819.cpp 相同
### .c
因為 C 中沒有像 C++ 的 std::map 或 Python 的 dict 這種資料結構，所以在 819.c 中分別使用 word_record_list 與 freq 這兩個 array 來紀錄單字與頻率
1. 將 paragraph 中的所有字元轉小寫
2. 以預先定義好的標點符號們分割 paragraph，並個別對的單字作處裡
3. 遍歷 freq array，找出頻率最高的單字的 index
4. 回傳對應的單字 (word_record_list[index])
819. Most Common Word
- 819.cpp
    > 先將 banned 中的元素從 vector 轉移到 unordered_set，為了提升之後的查找效率。
    > 接著處理 paragraph 中的字元，若為字母則轉為小寫，若為標點符號則轉為空白。
    > 最後將 paragraph 以空白分割，針對每個單字去處理。
- 819.py
    > 作法與 819.cpp 相同
- 819.c
    > 因為 C 中沒有像 C++ 的 std::map 或 Python 的 dict 這種資料結構，所以在 819.c 中分別使用 word_record_list 與 freq 這兩個 array 來紀錄單字與頻率
    >1. 將 paragraph 中的所有字元轉小寫
    >2. 以預先定義好的標點符號們分割 paragraph，並個別對的單字作處裡
    >3. 遍歷 freq array，找出頻率最高的單字的 index
    >4. 回傳對應的單字 (word_record_list[index])
819. Most Common Word
- 819.cpp
    > 先將 banned 中的元素從 vector 轉移到 unordered_set，為了提升之後的查找效率。
    > 接著處理 paragraph 中的字元，若為字母則轉為小寫，若為標點符號則轉為空白。
    > 最後將 paragraph 以空白分割，針對每個單字去處理。
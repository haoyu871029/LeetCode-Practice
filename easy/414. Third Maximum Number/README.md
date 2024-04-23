## 414. Third Maximum Number
### .cpp
- version 1
    > 每輪找出 vector 中的最大值，並移除該元素。重複三輪後，vector 中找出的最大值即為第三大的數字。若 vector 中不存在第三大的數，vector 必定會在三輪內清空，此時回傳原 vector 中的最大值。
    > - 利用 max_element() 得到 vector 中的最大值
    > - 利用 remove() 搭配 erase() 來移除 vector 中的特定元素
- version 2
    > 先將 vector 中的元素排序，接著遍歷 vector，利用 count 變數記錄相異數字個數，當 count 紀錄到 3 時，即可回傳第三大的數字。若 for loop 結束後還沒有回傳值，代表 vector 中不存在第三大的數字，此時回傳 vector 中的最大值。
    > - 利用 sort() 將 vector 中的元素排序，其中參數 greater<int>() 代表要做的是降序排列。

version 2 應該會比 version 1 有效率
### .py
解題概念與流程和 .cpp version 1 相同
- 利用 max() 找出 list 中的最大值
- 使用 list comprehension 移除 list 中的特定元素
### .c
先將 array 中的元素排序，接著遍歷 array，利用 count 變數記錄相異數字個數，當 count 紀錄到 3 時，即可回傳第三大的數字。
若遍歷完 array 後 count<3，代表 array 中不存在第三大的數字。
(其實 count<3 可以同時檢查情況一與情況二)，也就是說前面的 if (numsSize < 3) 可以不用判斷。
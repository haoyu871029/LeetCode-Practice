414. Third Maximum Number
- 414.cpp
    >每輪找出 vector 中的最大值，並移除該元素。重複三輪後，vector 中找出的最大值即為第三大的數字。
    >若 vector 中不存在第三大的數，vector 必定會在三輪內清空，此時回傳原 vector 中的最大值。
    >- 利用 max_element() 找出 vector 中的最大值
    >- 利用 remove() 和 erase() 移除 vector 中的特定元素
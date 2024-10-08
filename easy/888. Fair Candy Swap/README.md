# [888. Fair Candy Swap](https://leetcode.com/problems/fair-candy-swap/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)
## Introduction
題目的描述

```
Example

Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]
Explanation:
```

其他線索或限制如下:
- xxx
- xxx
## .cpp
### Version 0
**< Description >**

把解題邏輯描述一遍

```
像程式碼，但又像描述
用寫程式碼的方式寫出邏輯來
不要像源碼那麼複雜，但又要符合源碼的邏輯
把一些太細節的部分省略掉
```

**< Discussions >**
1. xxx ?
    > 感覺把 bob 也用一個 unordered_set 去存，就可以做到和 version 1 差不多的效果了，也不用去想 del 
2. xxx ?
    > 

**< Analysis >**
n = aliceSizes.size()  
m = bobSizes.size()
- Time complexity: O(n＊m)
- Space complexity: O(1)
### Version 1
**< Description >**

把解題邏輯描述一遍

```
像程式碼，但又像描述
用寫程式碼的方式寫出邏輯來
不要像源碼那麼複雜，但又要符合源碼的邏輯
把一些太細節的部分省略掉
```

**< Discussions >**
1. xxx ?
    > xxx
2. xxx ?
    > 

**< Analysis >**
n = alice.size()  
m = bob.size()
- Time complexity: O(n+m)
- Space complexity: O(m)
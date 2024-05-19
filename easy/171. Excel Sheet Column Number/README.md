# 171. Excel Sheet Column Number
## Description
[leetcode](https://leetcode.com/problems/excel-sheet-column-number/description/)

給定一個字串 columnTitle，代表 Excel 表中的某行行標題(column title)，請回傳其對應的行號(column number)，對應關係舉例如下: (column title -> column number)

```
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
```

Example
- Input: columnTitle = "AB"
- Output: 28
## .cpp
### Version 1
遍歷 columnTitle 一次，每次將目前的字母元素轉換成數字再乘以 26 的 i 次方，並累加到 result，舉例如下:
```
"ABC" = (1 * 26^2) + (2 * 26^1) + (3 * 26^0) = 731
```
這個作法的分析如下
- 時間複雜度: 雖然外部循環的複雜度是 O(n)，但 pow() 的實作會進行乘法運算直到指定的指數，因此可能會使整個函數的時間複雜度遠大於 O(n)
- 空間複雜度: O(1)
### Version 2
這個作法可以想像成是不斷再將字串做左移一位的動作，舉例如下:
```
"ABC" = 
reault = (0*26) + (1) = 1
reault = (1*26) + (2) = 28
reault = (28*26) + (3) = 731
```
這個作法的分析如下
- 時間複雜度: 時間複雜度是 O(n)，因為在每次迭代中只進行一次乘法和一次加法。
- 空間複雜度: O(1)

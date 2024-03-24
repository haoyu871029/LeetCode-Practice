## 1979. Find Greatest Common Divisor of Array
輸入是一串數字，求出這串數字中，最大值和最小值的最大公因數(GCD)

Example
- input: nums = [2,5,6,9,10]
- output: 2
### .cpp
先求出 nums 中的最大值與最小值，再利用 Euclidean Algorithm 求出兩者的最大公因數 (GCD)
- 求出 nums 中的最大值與最小值
    - version 1: 利用 minmax_element
    - version 2: 利用手動遍歷
### .py
先利用 min(), max() 找出 list 中的最大最小數，再利用 Euclidean Algorithm 求出兩者的最大公因數 (GCD)
### .c
先利用遍歷的方式找出 array 中的最大最小數，再利用 Euclidean Algorithm 求出兩者的最大公因數 (GCD)
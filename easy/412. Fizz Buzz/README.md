## 412. Fizz Buzz
[leetcode](https://leetcode.com/problems/fizz-buzz/)

給定一個整數 n，列印出 1~n 每個數字的對應結果。
- 若是 3 的倍數，輸出 "Fizz"
- 若是 5 的倍數，輸出 "Buzz"
- 若是 3 和 5 的倍數，輸出 "FizzBuzz"
- 其他情況，則輸出自己本身(數字)

Example
- Input: n = 15
- Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
### .cpp
用迴圈去處理 1~n 每個數字，並利用 if - else if - else 去作判斷。
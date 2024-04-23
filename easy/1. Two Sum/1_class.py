from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]: #不指定參數型態也不會影響程式的運行
        dict={} #{ partner_number:own_index, ... }
        for i,n in enumerate(nums): #i: index, n: number
            if n in dict: #當前數字是否是之前出現過的數字的夥伴
                return dict[n],i 
                #在 return 時使用 "," 分隔多個值時，這些值會被打包成一個 Tuple
                #Python 是一種動態語言，也就是說變數型態是在執行時確定的，而非編譯時。
            else:
                dict[target-n]=i

if __name__ == "__main__": #此行以下的程式碼只有在此.py檔被直接運行時才會被執行，若作為module被import到其他.py檔中是不會被執行的。
    nums = [2,7,11,15]
    target = 9
    s = Solution()
    print(s.twoSum(nums,target))

#python3 1_class.py
class Solution(object):
    def findNumbers_1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for n in nums:
            digits = 0
            while (n != 0):
                digits += 1
                n /= 10
            if (digits%2 == 0):
                result += 1
        return result
    def findNumbers_2(self, nums):
        return len([s for s in nums if len(str(s))%2 == 0])
    
if __name__ == '__main__':
    s = Solution()
    nums = [12,345,2,6,7896]
    print(s.findNumbers_2(nums))

# python3 1295.py
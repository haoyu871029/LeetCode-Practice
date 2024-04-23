class Solution(object):
    def findGCD(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_num = min(nums)
        max_num = max(nums)
        if (max_num%min_num == 0):
            return min_num
        """ Euclidean Algorithm """
        a = max_num
        b = min_num
        while (b != 0):
            tmp = b
            b = a % b
            a = tmp
        return a

if __name__ == '__main__':
    nums = [2,5,6,9,10]
    solution = Solution()
    print(solution.findGCD(nums))

#python3 1979.py
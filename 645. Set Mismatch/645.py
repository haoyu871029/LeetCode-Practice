class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        result = [None] * 2
        record = [0] * l
        for n in nums:
            record[n-1] += 1
        for i in range(l):
            if (record[i] == 2):
                result[0] = i+1
            elif (record[i] == 0):
                result[1] = i+1
        return result
if __name__ == "__main__":
    print(Solution().findErrorNums([1,2,2,4]))
    print(Solution().findErrorNums([1,1]))
    print(Solution().findErrorNums([2,2]))
    print(Solution().findErrorNums([3,2,3,4,6,5]))
    print(Solution().findErrorNums([1,5,3,2,2,7,6,4,8,9]))

#python3 645.py
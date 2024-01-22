class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = 0
        l = len(nums)
        for j in range(l):
            if (nums[j] != 0):
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        for j in range(i,l):
            nums[j] = 0
if __name__ == '__main__':
    nums = [0,1,0,3,12]
    Solution().moveZeroes(nums)
    print(nums)

# cd "283. Move Zeroes"
# python 283.py
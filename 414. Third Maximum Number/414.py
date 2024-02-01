class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_num = max(nums)
        filtered_list = nums
        for i in range(3):
            if not filtered_list:
                return max_num
            tmp_max_num = max(filtered_list)
            filtered_list = [num for num in filtered_list if num != tmp_max_num] #list comprehension
        return tmp_max_num
    
if __name__ == '__main__':
    solution = Solution()
    print(solution.thirdMax([2, 2, 3, 1]))

#python3 414.py
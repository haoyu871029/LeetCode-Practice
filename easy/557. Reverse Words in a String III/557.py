class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        stk = []
        result = ""
        for c in s:
            if (c != ' '):
                stk.append(c)
            else:
                for i in range(len(stk)):
                    result += stk.pop()
                result += ' '
        for i in range(len(stk)):
            result += stk.pop()
        return result

if __name__ == "__main__":
    s = Solution()
    print(s.reverseWords("Let's take LeetCode contest"))

#python3 557.py
class Solution(object):
    def capitalizeTitle(self, title):
        """
        :type title: str
        :rtype: str
        """
        result = ""
        words = title.split()
        for word in words:
            if (len(word) <= 2):
                for c in word:
                    result += c.lower()
            else:
                result += word[0].upper()
                for c in word[1:]:
                    result += c.lower()
            result += ' '
        result = result[:-1]
        return result

if __name__ == "__main__":
    print(Solution().capitalizeTitle("i love solving problems and it is fun"))
    print(Solution().capitalizeTitle("wHy DoeS A biRd Fly?"))
    print(Solution().capitalizeTitle("wHy DoeS A biRd Fly?"))
    print(Solution().capitalizeTitle("THE vitamins ARE IN my fresh CALIFORNIA raisins"))
    print(Solution().capitalizeTitle("the vitamins are in my"))

#python3 2129.py          
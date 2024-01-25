import string

class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        result = ""
        max_freq = 0
        freq = {}
        banned_set = set(banned)

        new_paragraph = ''.join([' ' if c in string.punctuation else c.lower() for c in paragraph])
        words = new_paragraph.split()
        for word in words:
            freq[word] = freq.get(word, 0) + 1
            # print(word, " ", freq[word])
            if (word not in banned_set) and (max_freq < freq[word]):
                max_freq = freq[word]
                result = word
        return result
        
if __name__ == "__main__":
    print(Solution().mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", ["hit"]))

# python3 819.py
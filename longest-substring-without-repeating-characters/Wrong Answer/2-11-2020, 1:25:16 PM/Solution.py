// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        curr_len = 0
        hash_map = {}
        
        for idx, letter in enumerate(s):
            if letter not in hash_map:
                hash_map[letter] = idx
                curr_len += 1
            else:
                if curr_len > max_len:
                    max_len = curr_len
                if (idx - hash_map[letter] < curr_len):
                    curr_len = idx - hash_map[letter]
                hash_map[letter] = idx
        if curr_len > max_len:
            return curr_len
        else:
            return max_len
            
        
// https://leetcode.com/problems/rearrange-spaces-between-words

class Solution(object):
    def reorderSpaces(self, text):
        words = [w for w in text.split(' ') if len(w) > 0]
        num_spaces = text.count(' ')
        if len(words) == 0:
            return text
        if len(words) == 1:
            return words[0] + num_spaces * ' '
        space_len = num_spaces/(len(words) - 1)
        ret = ""
        for i in range(len(words) - 1):
            w = words[i]
            ret += w 
            ret += space_len * ' '
            num_spaces -= space_len
        ret += words[-1] + num_spaces * ' '
        return ret 
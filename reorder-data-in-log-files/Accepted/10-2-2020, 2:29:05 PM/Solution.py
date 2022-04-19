// https://leetcode.com/problems/reorder-data-in-log-files

class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        
        
        def getKey(log):
            
            _id, key = log.split(" ", 1)
            
            if key[0].isalpha():
                return (0, key, _id)
            else:
                return (1, )
        return sorted(logs, key=getKey)
    
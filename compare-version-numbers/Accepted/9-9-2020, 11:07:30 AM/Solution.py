// https://leetcode.com/problems/compare-version-numbers

class Solution(object):
    def compareVersion(self, version1, version2):
        v1 = [int(i) for i in version1.split('.')]
        v2 = [int(i) for i in version2.split('.')] 
        for i in range(max(len(v1), len(v2))):
            v1n = 0
            v2n = 0
            if i < len(v1):
                v1n = v1[i]
            if i < len(v2):
                v2n = v2[i]
            if v1n > v2n:
                return 1
            elif v1n < v2n:
                return -1
        return 0
                
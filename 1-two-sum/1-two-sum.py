class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        '''
            A
            [.k.] v
            
            v + k = target, k in A
            
            hm[target - v] : i
            
            
            hm{1->2, 3->4, 5->6}
            [_, _, _]
            
            f {N} => {0, 1, 2}
            
            1 -> f -> i
            3 -> f -> i
            
            5 -> f -> j
            
            
            under the hood: 
            3 -> f -> i -> 4
            
            5 -> f -> j
            
            i: 1->2, 3->4
            j: 5->6
            
            hm[3] -> 4
        '''
        
        h = dict()
        for i in range(len(nums)):
            if target - nums[i] in h:
                return [i, h[target - nums[i]]]
            h[nums[i]] = i
        return []
        
        
        
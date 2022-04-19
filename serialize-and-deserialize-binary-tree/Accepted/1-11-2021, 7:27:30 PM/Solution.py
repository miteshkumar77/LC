// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Codec:
    
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = []
        
        def helper(root):
            if root == None:
                ans.append('_')
                return
            ans.append(str(root.val))
            helper(root.left)
            helper(root.right)
        
        helper(root)
        return ','.join(ans)
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        arr = data.split(',')
        
        if arr[0] == '_' :
            return None
        
        d = [[TreeNode(int(arr[0])), 0]]
        ret = d[0][0]
        i = 1
        while i < len(arr) or len(d) != 0:
            if i < len(arr):
                if arr[i] == '_':
                    if len(d) == 0:
                        break
                    if d[-1][1] == 1:
                        d.pop()
                    else:
                        d[-1][1] += 1
                else:
                    tmp = TreeNode(int(arr[i]))
                    if (d[-1][1] == 0):
                        d[-1][0].left = tmp
                        d[-1][1] += 1
                    else:
                        d[-1][0].right = tmp
                        d.pop();
                    d.append([tmp, 0])
            i += 1
        return ret
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
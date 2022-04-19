// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        ans = []
        def helper(node):
            if node == None:
                ans.append('_')
                return
            ans.append(str(node.val))
            helper(node.left)
            helper(node.right)
        helper(root)
        # print(','.join(ans))
        return ','.join(ans)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(',')
        if len(data) == 1:
            return None
        
        # print(data)
        
        root = None
        stk = []
        
        for i in data:
            if i == '_':
                stk[-1][1] += 1
                if stk[-1][1] == 2:
                    stk.pop()
            else:
                v = TreeNode(int(i))
                if len(stk) > 0:
                    if stk[-1][1] == 0:
                        stk[-1][0].left = v
                        stk[-1][1] += 1
                    else:
                        stk[-1][0].right = v
                        stk.pop()
                else:
                    root = v
                stk.append([v, 0])
        return root
                
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
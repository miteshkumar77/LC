// https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Codec:
    def serialize(self, root):
        if root == None:
            return ""
        ret = "(" + str(root.val)
        for c in root.children:
            ret += "," + self.serialize(c)
        return ret + ")"
    
		
    
    def deserialize(self, data):
        
        if len(data) == 0:
            return None
        def helper(i, s):
            rval = ""
            val = ""
            children = []
            
            while s[i:i+1].isdigit():
                rval += s[i]
                i += 1
            
            x = i
            
            while x < len(s):
                
                if s[x:x+1].isdigit():
                    print("ERROR!!!")
                    return None
                else:
                    if s[x] == '(':
                        r = helper(x + 1, s)
                        x = r[0]
                        children.append(r[1])
                    elif s[x] == ')':
                        return (x, Node(int(rval), children))
                x += 1
                
            return (-1, Node(int(rval), children))
                
            
            
        return helper(0, data[1:len(data) - 1])[1]
                    
        
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
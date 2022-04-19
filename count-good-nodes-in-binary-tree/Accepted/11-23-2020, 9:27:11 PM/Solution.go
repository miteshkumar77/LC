// https://leetcode.com/problems/count-good-nodes-in-binary-tree

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func goodNodes(root *TreeNode) int {
    ans := 0
    var v func(*TreeNode,int) 
    
    v = func(r *TreeNode, parent int) {
        if r == nil {
            return
        }
        
        if r.Val >= parent {
            parent = r.Val
            ans++
        }
        v(r.Left, parent)
        v(r.Right, parent)
    }
    
    v(root, -10001)
    return ans
}
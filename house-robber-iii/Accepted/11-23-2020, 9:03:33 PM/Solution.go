// https://leetcode.com/problems/house-robber-iii

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func Max(x, y int) int {
    if x < y {
        return y
    }
    return x
}

func rob(root *TreeNode) int {
    var v func(r *TreeNode) (int,int)
    
    v = func(r *TreeNode) (int,int) {
        if r == nil {
            return 0, 0
        } else {
            rli, rle := v(r.Left)
            rri, rre := v(r.Right)
            include := r.Val + rle + rre
            exclude := Max(rle, rli) + Max(rri, rre)
            return include, exclude
        }
    }

    ri , re := v(root); 
    return Max(ri, re)
}
// https://leetcode.com/problems/range-sum-of-bst

/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def rangeSumBST(root: TreeNode, L: Int, R: Int): Int = {
        if (root == null) {
            return 0;
        }
        
        val ret : Int = (if (root.value >= L && root.value <= R) root.value else 0) +
        (if (root.value < R) rangeSumBST(root.right, L, R) else 0) +
        (if (root.value > L) rangeSumBST(root.left, L, R) else 0)
        
        return ret
        
    }
}
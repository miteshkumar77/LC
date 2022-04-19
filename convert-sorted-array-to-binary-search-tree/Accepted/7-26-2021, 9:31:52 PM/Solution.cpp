// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> const & nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int mid = nums.size()/2;
        return new TreeNode(nums[mid],
        sortedArrayToBST(vector<int>(nums.begin(), nums.begin() + mid)),
        sortedArrayToBST(vector<int>(nums.begin() + mid + 1, nums.end())));
    }
};
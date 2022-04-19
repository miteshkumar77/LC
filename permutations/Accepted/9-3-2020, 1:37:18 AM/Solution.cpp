// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        bt(ans, nums, 0); 
        return ans; 
    }
    
    
    void bt(vector<vector<int>>& ans, vector<int>& box, int i) {
        if (i == box.size()) {
            ans.push_back(box); 
            return; 
        }
        for (int x = i; x < box.size(); ++x) {
            swap(box[x], box[i]); 
            bt(ans, box, i + 1); 
            swap(box[x], box[i]); 
        }
    }
};
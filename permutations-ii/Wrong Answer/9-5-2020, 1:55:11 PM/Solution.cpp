// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans; 
        bt(ans, nums, 0); 
        return ans; 
    }
    
    
    void bt(vector<vector<int>>& ans, vector<int>& box, int s) {
        if (s == box.size()) {
            ans.push_back(box); 
            return; 
        }
        
        sort(box.begin() + s, box.end()); 
        for (int i = s; i < box.size(); ++i) {
            if (i == s || box[i] != box[i - 1]) {
                swap(box[s], box[i]); 
                bt(ans, box, s + 1);
                swap(box[s], box[i]); 
            }
        }
    } 
};
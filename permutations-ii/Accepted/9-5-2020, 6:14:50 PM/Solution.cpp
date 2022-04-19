// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans; 
        bt(ans, nums, 0); 
        return ans; 
    }
    
    void bt(vector<vector<int>>& ans, vector<int>& box, int s) {
        if (s == box.size()) {
            ans.push_back(box); 
            return; 
        }
        
        unordered_set<int> done; 
        for (int i = s; i < box.size(); ++i) {
            if (done.find(box[i]) == done.end()) {
                done.insert(box[i]); 
                swap(box[i], box[s]);
                bt(ans, box, s + 1); 
                swap(box[i], box[s]); 
            }
        }
    }
    
    
};
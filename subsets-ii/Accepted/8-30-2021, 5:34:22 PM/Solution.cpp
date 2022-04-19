// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    void bt(unordered_map<int,int>& ct, unordered_map<int,int>::iterator curr, vector<int>& box, vector<vector<int>>& ans) {
        if (curr == ct.end()) {
            ans.push_back(box);
            return;
        }
        
        bt(ct, next(curr), box, ans);
        for (int i = 0; i < curr->second; ++i) {
            box.push_back(curr->first);
            bt(ct, next(curr), box, ans);
        }
        for (int i = 0; i < curr->second; ++i) {
            box.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;    
        unordered_map<int,int> ct;
        for (int i : nums) ++ct[i];
        vector<int> box;
        bt(ct, ct.begin(), box, ans);
        return ans;
    }
};
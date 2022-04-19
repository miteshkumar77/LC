// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        unordered_map<int,int> ct;
        for (int i : nums) ++ct[i];
        vector<vector<int>> ans;
        vector<int> box;
        function<void(unordered_map<int,int>::iterator)> bt = [&](unordered_map<int,int>::iterator it) -> void {
            if (it == ct.end()) {
                ans.push_back(box);
                return;
            }
            
            bt(next(it));
            for (int i = 1; i <= it -> second; ++i) {
                box.push_back(it -> first);
                bt(next(it));
            }
            for (int i = 1; i <= it -> second; ++i) {
                box.pop_back();
            }
        };
        bt(ct.begin());
        return ans;
    }
};
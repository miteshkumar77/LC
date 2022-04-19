// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        unordered_map<int,int> pos;
        for (int i = 0; i < n; ++i) {
            pos[arr[i]] = i;
        }
        unordered_set<int> ndistinct;
        for (auto const& p : pieces) {
            if (!p.empty() && !pos.count(p[0])) return false;
            ndistinct.insert(p[0]);
            for (int i = 1; i < p.size(); ++i) {
                if (!pos.count(p[i]) || pos[p[i]] != pos[p[i-1]]+1) return false;
                ndistinct.insert(p[i]);
            }
        }
        return ndistinct.size() == arr.size();
    }
};
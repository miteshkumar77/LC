// https://leetcode.com/problems/remove-interval

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& rem) {
        vector<vector<int>> ans;
        for (auto interval : intervals) {
            vector<vector<int>> to_add;
            to_add.push_back(vector<int>{interval[0], min(interval[1], rem[0])});
            to_add.push_back(vector<int>{max(rem[1], interval[0]), interval[1]}); 
            for (auto add : to_add) {
                if (add[0] < add[1]) {
                    ans.push_back(add);
                }
            }
        }
        return ans;
    }
};
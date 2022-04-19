// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int> > stk; 
        vector<int> ans(T.size(), 0); 
        for (int i = 0; i < T.size(); ++i) {
            while(!stk.empty() && T[i] > stk.top().first) {
                auto tp = stk.top(); stk.pop(); 
                ans[tp.second] = i - tp.second; 
            }
            stk.push(make_pair(T[i], i)); 
        }
        return ans; 
    }
};
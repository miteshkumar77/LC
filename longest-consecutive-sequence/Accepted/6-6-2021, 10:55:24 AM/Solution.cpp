// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq(nums.begin(), nums.end());
        int ans = 0;
        int sub;
        for (int i : nums) {
            sub = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int t = q.front(); q.pop();
                if (seq.count(t)) {
                    seq.erase(t);
                    ++sub;
                    q.push(t-1);
                    q.push(t+1);
                }
            }
            ans = max(ans, sub);
        }
        return ans;
    }
};
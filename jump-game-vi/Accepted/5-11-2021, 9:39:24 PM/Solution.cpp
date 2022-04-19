// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = 0;
        int sz = 0;
        int ans = 0;
        deque<array<int,2>> q;
        for (int i : nums) {
            ans = mx + i;
            array<int, 2> add{ans, 1};
            while(!q.empty() && q.back()[0] <= add[0]) {
                add[1] += q.back()[1];
                q.pop_back();
            }
            q.push_back(add);
            mx = q.front()[0];
            if (++sz == k) {
                --sz;
                if (--q.front()[1] == 0) {
                    q.pop_front();
                }
            }
            // for (auto p : q) cout << p[0] << ' ' << p[1] << ",";
            // cout << endl;
        }
        return ans;
    }
};

// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        /* 10:27 */
        int n = nums.size();
        deque<array<int,2>> q;
        // q.push_back({0, 1});
        q.push_back({nums[0], 1});
        int ans = nums[0];
        int sz = 1;
        for (int i = 1; i < n; ++i) {
            ans = nums[i] + q.front()[0];
            array<int,2> put{ans, 1};
            while(!q.empty() && q.back()[0] <= put[0]) {
                put[1] += q.back()[1];
                q.pop_back();
            }
            q.push_back(put);
            if (++sz > k) {
                if (--q.front()[1] == 0) {
                    q.pop_front();
                }
                --sz;
            }
        }
        return ans;
    }
};
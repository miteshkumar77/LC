// https://leetcode.com/problems/constrained-subsequence-sum

class Solution {
public:
    // Solution() {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);
    // }
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<pair<int, int>> dq; 
        int sz = 0; 
        function<void(int)> enque = [&](int val) -> void {
            int ct = 1; 
            while(!dq.empty() && val >= dq.back().first) {
                ct += dq.back().second; 
                dq.pop_back(); 
            }
            dq.push_back(make_pair(val, ct));
        };
        
        function<void()> pop = [&]() -> void {
            int ret = dq.front().first; 
            --dq.front().second; 
            if (dq.front().second == 0) {
                dq.pop_front(); 
            }
        };
        
        int global_ans = nums[0]; 
        int local_ans = nums[0]; 
        // vector<int> dp(nums.size()); 
        // dp[0] = nums[0]; 
        enque(nums[0]); 
        for (int i = 1; i < nums.size(); ++i) {
            local_ans = max(nums[i] + dq.front().first, nums[i]); 
            global_ans = max(local_ans, global_ans); 
            enque(local_ans); 
            if (i >= k) {
                pop(); 
            }
        }
        return global_ans; 
    }
};
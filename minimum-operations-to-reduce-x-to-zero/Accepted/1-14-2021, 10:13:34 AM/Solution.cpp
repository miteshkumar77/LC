// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        x = accumulate(nums.begin(), nums.end(), 0) - x;
        if (x < 0) {
            return -1;
        }
        if (x == 0) {
            return nums.size();
        }
        
        int j = 0;
        int sum = 0;
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum > x) {
                sum -= nums[j++];
            }
            if (sum == x) {
                ans = max(ans, i - j + 1);
            }
        }
        return ans == -1?ans:nums.size() - ans;
    }
};
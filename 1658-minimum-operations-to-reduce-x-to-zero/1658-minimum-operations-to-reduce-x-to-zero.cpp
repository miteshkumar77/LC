class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int t = accumulate(nums.begin(), nums.end(), 0);
        int j = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            t -= nums[i];
            while(j <= i && t < x) {
                t += nums[j++];
            }
            if (t == x) {
                ans = min(ans, n - (i - j + 1));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
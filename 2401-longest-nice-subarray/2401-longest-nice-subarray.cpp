class Solution {
public:
    using ll = long long;
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int x = nums[0];
        int m = 1;
        for (int i = 1; i < nums.size(); ++i) {
           while((x & nums[i]) != 0) {
               x &= (~nums[l++]);
           }
           x |= nums[i];
           m = max(m, i - l + 1);
        }
        return m;
    }
};
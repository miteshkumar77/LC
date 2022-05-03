class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefmax(n+2, INT_MIN);
        vector<int> suffmin(n+2, INT_MAX);
        for (int i = 1; i <= n; ++i)
            prefmax[i] = max(prefmax[i-1], nums[i-1]);
        for (int i = n; i >= 1; --i)
            suffmin[i] = min(suffmin[i+1], nums[i-1]);
        
        int s{n+1};
        int e{0};
        for (int i = 1; i <= n; ++i) {
            if (nums[i-1] > suffmin[i] || nums[i-1] < prefmax[i]) {
                s = min(s, i);
                e = max(e, i);
            }
        }
        return max(0, e - s + 1);
        
        
    }
};
// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int midl = nums[0];
        int jl = 0;
        int midu = nums[0];
        int ju = 0;
        int rightu = accumulate(nums.begin() + 1, nums.end(), 0);
        int ans = 0;
        int M = 1e9 + 7;
        for (int i = 0; i < nums.size() - 2; ++i) {
            left += nums[i];
            midl -= nums[i];
            midu -= nums[i];
            while(jl == i || (jl < n - 2 && midl < left)) {
                midl += nums[++jl];
            }
            while(ju == i || (ju < n - 2 && midu + nums[ju + 1] <= rightu - nums[ju + 1])) {
                midu += nums[++ju];
                rightu -= nums[ju];
            }
            // cout << jl << ' ' << midl << ' ' << ju << ' ' << midu << endl;
            // if (midl >= && midu <= rightu && rightu != 0 && ju >= jl) {
            if (midl >= left && midu >= left && midu <= rightu && ju >= jl) {
                ans += max(0, ju - jl + 1);
                ans = ans % M;
            }
        }
        return ans;
    }
    
    
    
    
};
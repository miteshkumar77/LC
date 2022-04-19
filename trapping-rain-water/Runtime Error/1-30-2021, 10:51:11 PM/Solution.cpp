// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        vector<int> pref_max(n);
        vector<int> suff_max(n);
        pref_max[0] = height[0];
        suff_max[n - 1] = height[n - 1];
        for (int i = 1, j = n - 2; i < n - 1; ++i, --j) {
            pref_max[i] = max(height[i], pref_max[i - 1]);
            suff_max[j] = max(height[j], suff_max[j + 1]); 
        }
        
        
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += max(0, min(pref_max[i - 1], suff_max[i + 1]) - height[i]);             
        }
        
        return ans;
        
        
    }
};


// vector<int> suff_max_height(n, 0);
//         vector<int> suff_max_index(n, n); 
//         vector<int> suff_vol(n, 0);
//         int suff_height = 0;
//         for (int i = n - 1; i >= 0; --i) {
//             if (height[i] >= suff_height) {
//                 suff_height = height[i];
//                 suff_vol[i] = 0;
//                 suff_max_index[i] = i;
//             } else {
//                 suff_vol[i] = suff_vol[i + 1] + suff_height - height[i]; 
//                 suff_max_index[i] = suff_max_index[i + 1];
//             }
//             suff_max_height[i] = suff_height;
//         }
        

        
//         int pref_max_height = 0;
//         int pref_vol = 0;
//         int pref_max_index = -1; 
//         int ans = 0;
//         int tmp_vol;
//         for (int i = 0; i < n; ++i) {
//             if (height[i] >= pref_max_height) {
//                 pref_max_index = i;
//                 pref_vol = 0;
//                 pref_max_height = height[i]; 
//             } else {
//                 pref_vol += pref_max_height - height[i]; 
//                 tmp_vol = pref_vol + suff_vol[i];
//                 if (pref_max_height > suff_max_height[i]) {
//                     tmp_vol -= (pref_max_height - suff_max_height[i]) * (i - pref_max_index); 
//                 } else {
//                     tmp_vol -= (suff_max_height[i] - pref_max_height) * (suff_max_index[i] - i); 
//                 }
//                 tmp_vol -= (min(pref_max_height, suff_max_height[i])) - height[i]; 
//                 ans = max(ans, tmp_vol); 
//             }
//         }
//         return ans;
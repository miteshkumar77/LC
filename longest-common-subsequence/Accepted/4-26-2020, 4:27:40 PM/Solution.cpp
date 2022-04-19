// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // LCS -> LIS
        vector<int> alph[128];  // record text1's alphabet in text2 pos.
        int maps[128];
        memset(maps, 0, sizeof(maps));
        for(int i = 0; i < text1.size(); i++) maps[text1[i]] = 1;
        
        for(int j = text2.size(); j > -1; j--) if(maps[text2[j]] == 1) alph[text2[j]].push_back(j);
        vector<int> nums;
        for(int i = 0; i < text1.size(); i++) {
            if(alph[text1[i]].size() > 0) nums.insert(nums.end(), alph[text1[i]].begin(), alph[text1[i]].end());
        }
        
        // get LIS's length by monotone stack method : O(nlogn)
        vector<int> pool;
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i] > pool.back() ) {
                pool.push_back(nums[i]);
            } else if(nums[i] == pool.back()) {
                continue;
            } else {
                int s = 0, e = pool.size() - 1, mid = 0;
                while(s < e) {
                    mid = (s + e)/2;
                    if(pool[mid] < nums[i]) s = mid + 1;
                    else e = mid;
                }
                pool[e] = nums[i];
            }
        }
        
        return pool.size();
    }
};
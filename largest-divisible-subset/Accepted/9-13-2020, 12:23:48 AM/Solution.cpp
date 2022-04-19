// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>(); 
        }
        sort(nums.begin(), nums.end()); 
        vector<int> prev(nums.size(), -1); 
        vector<int> sz(nums.size(), 1); 
        int maxr = 0; 
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (sz[j] + 1 > sz[i]) {
                        sz[i] = sz[j] + 1; 
                        prev[i] = j; 
                        if (sz[maxr] < sz[i]) {
                            maxr = i; 
                        }    
                    }
                }
            }
        }
        
        vector<int> ans; 
        while(maxr != -1) {
            ans.push_back(nums[maxr]); 
            maxr = prev[maxr]; 
        }
        return ans; 
    }
};
// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0; 
        }
        unordered_map<int, int> ct; 
        for (int i : nums) {
            ++ct[i]; 
        }
        
        vector<int> collection; collection.reserve(ct.size());  
        for (auto p : ct) {
            collection.push_back(p.first); 
        }
        sort(collection.begin(), collection.end()); 
        
        vector<int> dp(collection.size() + 1); 
        dp[0] = 0; 
        dp[1] = collection[0] * ct[collection[0]]; 
        for (int i = 2; i <= collection.size(); ++i) {
            if (collection[i - 1] == collection[i - 2] + 1) {
                dp[i] = max(dp[i - 1], dp[i - 2] + collection[i - 1] * ct[collection[i - 1]]); 
            } else {
                dp[i] = dp[i - 1] + collection[i - 1] * ct[collection[i - 1]]; 
            }
        }
        return dp.back(); 
    }
};
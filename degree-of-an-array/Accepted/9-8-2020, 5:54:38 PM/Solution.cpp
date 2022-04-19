// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> ct; 
        unordered_map<int,int> first; 
        unordered_map<int,int> last; 
        int maxf = 0; 
        int idx = 0; 
        for (int i : nums) {
            ++ct[i]; 
            if (ct[i] > maxf) {
                maxf = ct[i]; 
            }
            first.insert(make_pair(i, idx)); 
            last[i] = idx; 
            ++idx; 
        }
        
        int ans = INT_MAX; 
        for (auto [key, value] : ct) {
            if (value == maxf) {
                ans = min(ans, last[key] - first[key] + 1); 
            }
        }
        return ans; 
        
        
    }
};
// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> diff_map; 
        int num_zeros = 0; 
        int num_ones = 0; 
        int ans = 0; 
        diff_map.insert(make_pair(0, 0)); 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++num_zeros; 
            } else {
                ++num_ones; 
            }
            
            auto it = diff_map.find(num_zeros - num_ones); 
            if (it != diff_map.end()) {
                ans = max(ans, i - (it -> second) + 1); 
            } else {
                diff_map.insert(make_pair(num_zeros - num_ones, i)); 
            }
        }
        return ans; 
    }
};
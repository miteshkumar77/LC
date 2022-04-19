// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> diff_map; 
        int count = 0; 
        int ans = 0; 
        diff_map.insert(make_pair(0, -1)); 
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++count; 
            } else {
                --count;  
            }
            
            auto it = diff_map.find(-count); 
            if (it != diff_map.end()) {
                ans = max(ans, i - (it -> second)); 
            }
            
            diff_map.insert(make_pair(count, i)); 
        }
        return ans; 
    }
};
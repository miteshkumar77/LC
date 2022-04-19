// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nstrings; nstrings.reserve(nums.size()); 
        
        for (int i = 0; i < nums.size(); ++i) {
            nstrings.push_back(to_string(nums[i])); 
        }
        
        sort(nstrings.begin(), nstrings.end(), [&](const string& x, const string& y) -> bool {
            return (x + y > y + x); 
        }); 
        
        
        string ans; 
        for (string s : nstrings) {
            ans += s; 
        }
        return ans; 
    }
};
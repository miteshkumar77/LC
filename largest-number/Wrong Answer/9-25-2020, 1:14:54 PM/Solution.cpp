// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nstrings; nstrings.reserve(nums.size()); 
        
        for (int i = 0; i < nums.size(); ++i) {
            nstrings.push_back(to_string(nums[i])); 
        }
        
        sort(nstrings.begin(), nstrings.end(), [&](const string& x, const string& y) -> bool {
            for (int i = 0; i < x.length() && i < y.length(); ++i) {
                if (x[i] > y[i]) {
                    return true; 
                }
                if (x[i] < y[i]) {
                    return false; 
                }
            }
            return x.length() < y.length(); 
        }); 
        string ans; 
        for (string s : nstrings) {
            ans += s; 
        }
        return ans; 
    }
};
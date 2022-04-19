// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> equal; equal.reserve(nums.size()); 
        
        for (int n : nums) {
            equal.push_back(to_string(n)); 
        }
        
        sort(equal.begin(), equal.end(), [] (const string& a, const string& b) -> bool {
            int len = min(a.length(), b.length()); 
            for (int i = 0; i < len; ++i) {
                if (a[i] > b[i]) {
                    return true; 
                } else if (b[i] > a[i]) {
                    return false; 
                }
            }
            return false; 
        }); 
        string ans = ""; 
        for (string s : equal) {
            ans += s; 
        }
        return ans; 
    }
};
// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> equal; equal.reserve(nums.size()); 
        
        for (int n : nums) {
            equal.push_back(to_string(n)); 
        }
        
        sort(equal.begin(), equal.end(), [] (const string& a, const string& b) -> bool {
            
            string sa = a + b; 
            string sb = b + a; 
            
            for (int i = 0; i < sa.length(); ++i) {
                if ((sa[i] - '0') > (sb[i] - '0')) {
                    return true; 
                } else if ((sa[i] - '0') < (sb[i] - '0')) {
                    return false; 
                }
            }
            return true; 
        }); 
        string ans = ""; 
        for (string s : equal) {
            ans += s; 
        }
        return ans; 
    }
};
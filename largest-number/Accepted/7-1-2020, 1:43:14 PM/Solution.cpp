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
            
            
            return sa > sb;  
        }); 
        
        if (equal[0] == "0") {
            return "0"; 
        }
        string ans = ""; 
        for (string s : equal) {
            ans += s; 
        }
        return ans; 
    }
};
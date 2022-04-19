// https://leetcode.com/problems/sequential-digits

class Solution {
public:
    
    
    
    vector<int> sequentialDigits(int low, int high) {
        string sl = to_string(low); string sh = to_string(high); 
        vector<int> ans; 
        
        for (int len = sl.length(); len <= sh.length(); ++len) {
            for (int st = 1; st <= 9 && (9 - st + 1 >= len); ++st) {
                string tmp; 
                for (int dig = st; tmp.length() < len; ++dig) {
                    tmp += to_string(dig); 
                }
                int res = stoi(tmp); 
                if (res >= low && res <= high) {
                    ans.push_back(res); 
                }
            }
        }
        return ans; 
    }
};
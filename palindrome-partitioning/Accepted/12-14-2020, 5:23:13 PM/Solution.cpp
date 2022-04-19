// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        function<bool(int,int)> isPal = [&](int l, int r) -> bool {
            while(l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };
        
        vector<vector<string>> ans;
        function<void(int,vector<string>&)> sol = [&](int i, vector<string>& box) -> void {
            if (i == n) {
                ans.push_back(box);
                return;
            } 
            
            for (int idx = i; idx < n; ++idx) {
                if (isPal(i, idx)) {
                    // cout << i << ' ' << idx << endl;
                    box.push_back(s.substr(i, idx - i + 1));
                    sol(idx + 1, box);
                    box.pop_back();
                }
            }
        };
        
        vector<string> tmp;
        sol(0, tmp);
        return ans;
    }
};
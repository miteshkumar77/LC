// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> box; 
        function<void(int,int,int)> bt = [&] (int n, int k, int i) -> void {
            if (n == 0 && k == 0) {
                ans.push_back(box); 
                return; 
            }
            
            if (n <= 0 || k <= 0 || i < 1) {
                return; 
            }
            if (n > (i + 1) * i /2) {
                return; 
            }
            box.push_back(i); 
            bt(n - i, k - 1, i - 1); 
            box.pop_back(); 
            bt(n, k, i - 1); 
        };
        bt(n, k, 9); 
        return ans; 
    }
    
    
};
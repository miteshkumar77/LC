// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        
        function<void(int,int,int,vector<int>&)> bt = [&] (int n, int k, int i, vector<int>& box) {
            if (n == 0 && k == 0) {
                ans.push_back(box); 
                return; 
            }
            
            if (n <= 0 || k <= 0 || i < 1) {
                return; 
            }
            
            box.push_back(i); 
            bt(n - i, k - 1, i - 1, box); 
            box.pop_back(); 
            bt(n, k, i - 1, box); 
        }; 
        
        vector<int> box; 
        bt(n, k, 9, box);
        return ans; 
    }
};
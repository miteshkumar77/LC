// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int> > ans; 
        vector<int> cand; 
        int curr_sum = 0; 
        generator(candidates, ans, cand, curr_sum, target, 0); 
        return ans; 
    }
    
    
    void generator(vector<int>& candidates, vector<vector<int> >& ans, vector<int>& cand, int& curr_sum, int target, int L) {
        
        if (curr_sum == target) {
            ans.push_back(cand); 
            return; 
        }
        
        
        for (int i = L; i < candidates.size(); ++i) {
            if (curr_sum + candidates[i] > target) {
                return; 
            }
            curr_sum += candidates[i]; 
            cand.push_back(candidates[i]); 
            generator(candidates, ans, cand, curr_sum, target, i); 
            curr_sum -= candidates[i]; 
            cand.pop_back(); 
        }
        
    }
};
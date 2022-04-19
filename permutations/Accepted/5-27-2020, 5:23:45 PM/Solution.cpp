// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        list<int> box; 
        generator(ans, box, nums, 0); 
        return ans; 
    }
    
    void generator(vector<vector<int> >& ans, list<int>& box, vector<int>& nums, int i) {
        if (box.size() == nums.size()) {
            ans.push_back(vector<int>(box.begin(), box.end())); 
            return; 
        }
        
        
        for (auto iter = box.begin(); iter!= box.end(); ++iter) {
            auto tmp = box.insert(iter, nums[i]);
            generator(ans, box, nums, i + 1); 
            box.erase(tmp); 
        }
        
        box.push_back(nums[i]); 
        generator(ans, box, nums, i + 1); 
        box.pop_back(); 
        
        
        
    }
};
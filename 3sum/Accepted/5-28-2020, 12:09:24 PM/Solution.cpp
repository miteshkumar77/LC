// https://leetcode.com/problems/3sum

struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if (nums.size() < 3) {
            return vector<vector<int> >(); 
        }
        
        vector<vector<int> > ans; 
        unordered_set<int> rems; 
        unordered_set< pair<int, int>,  pair_hash> pair_set; 
        
        for (int i = 1; i < nums.size(); ++i) {
            rems.insert(nums[i - 1]);
            for (int j = i + 1; j < nums.size(); ++j) {
                
                if (rems.find(-nums[i] - nums[j]) != rems.end()) {
                    vector<int> candidate{nums[i], nums[j], -nums[i] - nums[j]}; 
                    sort(candidate.begin(), candidate.end()); 
                    if (pair_set.find(pair<int, int>(candidate[0], candidate[1])) == pair_set.end()) {
                        pair_set.insert(pair<int, int>(candidate[0], candidate[1])); 
                        ans.push_back(candidate); 
                    }
                }
            }
        }
        
        return ans; 
        
        
        
        
    }
};
// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<vector<int> >(1, vector<int>()); 
        }
        vector<vector<int> > ans; 
        list<int> box; 
        unordered_map<int, int> num_map; 
        for (int num : nums) {
            auto iter = num_map.find(num); 
            if (iter == num_map.end()) {
                num_map.insert(pair<int, int>(num, 1)); 
            } else {
                ++(iter -> second); 
            }
        }
        
        enterNTimes(ans, box, nums, num_map, num_map.begin(), box.begin(), num_map.begin() -> second); 
        return ans; 
        
    }
    
    void enterNTimes(
        vector<vector<int> >& ans, 
        list<int>& box, 
        vector<int>& nums, 
        unordered_map<int, int>& num_map,
        unordered_map<int, int>::iterator map_iter, 
        list<int>::iterator from,
        int times
    ) {
        
        if (box.size() == nums.size()) {
            ans.push_back(vector<int>(box.begin(), box.end())); 
            return; 
        }
        
        if (times == 0) {
            int nexttimes = 0; 
            if (next(map_iter) != num_map.end()) {
                nexttimes = next(map_iter) -> second; 
            }
            enterNTimes(ans, box, nums, num_map, next(map_iter), box.begin(), nexttimes); 
            return; 
        }
        
        for (auto iter = from; iter != box.end(); ++iter) {
            auto tmp = box.insert(iter, map_iter -> first); 
            enterNTimes(ans, box, nums, num_map, map_iter, next(tmp), times - 1); 
            box.erase(tmp); 
        }
        
        box.push_back(map_iter -> first); 
        enterNTimes(ans, box, nums, num_map, map_iter, box.end(), times - 1); 
        box.pop_back(); 
    }
};
// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    
    
    
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> ct; 
        for (int i : nums) {
            if (ct.size() < 2 || ct.find(i) != ct.end()) {
                ++ct[i]; 
            } else {
                for (auto it = ct.begin(); it != ct.end(); ) {
                    --(it -> second);
                    if (it -> second == 0) {
                        it = ct.erase(it); 
                    } else {
                        ++it;
                    } 
                }
            }
        }
        
        for (auto p : ct) {
            ct[p.first] = 0;
        }
        for (int i : nums) {
            if (ct.find(i) != ct.end()) {
                ++ct[i]; 
            }
        }
        
        vector<int> ans; 
        for (auto p : ct) {
            if (p.second > (nums.size()/3)) {
                ans.push_back(p.first); 
            }
        }
        return ans; 
        
        
    }
};
// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        list<int> m{nums[0]}; 
        list<int> n{nums[0]}; 
        
        for (int i = 1; i < nums.size(); ++i) {
            for (auto it = m.begin(); it != m.end(); ++it) {
                if ((*it) <= nums[i]) {
                    m.insert(it, nums[i]); 
                    break;
                }
                if (next(it) == m.end()) {
                    m.push_back(nums[i]); 
                }
            }
            
            if (m.size() > 3) {
                m.pop_back(); 
            }
            
            for (auto itt = n.begin(); itt != n.end(); ++itt) {
                if ((*itt) >= nums[i]) {
                    n.insert(itt, nums[i]); 
                    break;
                }
                if (next(itt) == n.end()) {
                    n.push_back(nums[i]); 
                }
            }
            if (n.size() > 3) {
                n.pop_back(); 
            }
        }
        
        vector<int> mv(m.begin(), m.end()); 
        vector<int> nv(n.begin(), n.end()); 
        return max(mv[0] * mv[1] * mv[2], nv[0] * nv[1] * mv[0]); 
        
        
        
    }
};
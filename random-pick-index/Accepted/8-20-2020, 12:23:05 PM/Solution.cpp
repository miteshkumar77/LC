// https://leetcode.com/problems/random-pick-index

class Solution {
public:
    Solution(vector<int>& nums) {
        ns.swap(nums); 
    }
    
    int pick(int target) {
        int count = 0; 
        
        for (int i : ns) count += (i == target); 
        
        int idx = rand() % count; 
        int x = 0; 
        for (int i : ns) {
            if (i == target) {
                if (idx == 0) {
                    return x; 
                }
                --idx; 
            }
            ++x; 
        }
        return x; 
    }
private: 
    
    vector<int> ns; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
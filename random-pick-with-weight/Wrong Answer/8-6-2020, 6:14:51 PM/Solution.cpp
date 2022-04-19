// https://leetcode.com/problems/random-pick-with-weight

class Solution {
    
    
private: 
    vector<unsigned long long int> weights; 
public:
    Solution(vector<int>& w) {
        
        weights = vector<unsigned long long int>(w.size()); 
        weights[0] = w[0]; 
        for (int i = 1; i < w.size(); ++i) {
            weights[i] = weights[i - 1] + w[i]; 
        }
    }
    
    int pickIndex() {
        unsigned long long int randidx = rand() % weights.back(); 
        int L = 0; 
        int R = weights.size() - 1; 
        int ans = 0; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (mid < randidx) {
                ans = mid; 
                L = mid + 1; 
            } else {
                R = mid - 1; 
            }
        }
        return ans; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
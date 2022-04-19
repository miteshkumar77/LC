// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    Solution(vector<int>& w) {
        for (int i = 1; i < w.size(); ++i) {
            w[i] += w[i - 1]; 
        }
        W.swap(w); 
    }
    
    int pickIndex() {
        int N = rand() % W.back(); 
        
        int L = 0; int R = W.size() - 1; 
        int ans = R + 1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            
            if (W[mid] > N) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        
        return ans; 
    }
    
    
    vector<int> W; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
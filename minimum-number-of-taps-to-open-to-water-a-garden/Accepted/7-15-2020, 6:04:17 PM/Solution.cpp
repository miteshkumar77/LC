// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jump(n + 1, 0); 
        for (int i = 0; i <= n; ++i) {
            int l = max(0, i - ranges[i]);
            int r = min(n , i + ranges[i]); 
            jump[l] = max(jump[l], r - l); 
            
        }
        
        int curr_max = jump[0]; 
        int next_max = jump[0]; 
        int jumps = 1; 
        int i = 0; 
        while(i < ranges.size() - 1) {
            next_max = max(next_max, jump[i] + i);
            if (i == curr_max) {
                if (next_max == curr_max) {
                    return -1; 
                }
                curr_max = next_max; 
                ++jumps; 
            }
            ++i; 
        }
        
        return jumps; 
        
    }
};
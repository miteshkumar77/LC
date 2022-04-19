// https://leetcode.com/problems/magnetic-force-between-two-balls

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); 
        int L = 0; 
        int R = position.back(); 
        int ans = 0; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (possible(position, m, mid)) {
                ans = mid; 
                L = mid + 1; 
            } else {
                R = mid - 1; 
            }
        }
        return ans; 
    }
    
    
    bool possible(vector<int>& positions, int m, int k) {
        int lastpos = 0; 
        int left = m - 1; 
        for (int i = 1; i < positions.size(); ++i) {
            if (positions[i] - lastpos > k) {
                --left; 
                lastpos = positions[i]; 
            }
            if (left == 0) {
                return true; 
            }
        }
        return false; 
    }
};
// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while(tx >= sx && ty >= sy) {
            // cout << 
            if (tx > ty) {
                tx -= ty;
            } else {
                ty -= tx;
            }
            if (tx == sx && ty == sy) return true;
        }
        
        return false;
    }
};
// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while(tx >= sx && ty >= sy) {
            // cout << 
            if (tx > ty) {
                tx -= ty * max(((tx - sx)/ty), 1);
            } else {
                ty -= tx * max(((ty - sy)/tx), 1);
            }
            if (tx == sx && ty == sy) return true;
        }
        
        return false;
    }
};
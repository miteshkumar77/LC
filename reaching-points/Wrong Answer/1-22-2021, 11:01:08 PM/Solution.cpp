// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        while(tx > sx && ty > sy) {
            if (tx > ty) {
                tx -= ty;
            } else {
                ty -= tx;
            }
        }
        
        return tx == sx && ty == sy;
    }
};
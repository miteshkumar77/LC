// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string instructions) {
        array<int, 5> dir{0, 1, 0, -1, 0}; 
        int cdir = 0; 
        int x = 0;
        int y = 0; 
        for (char c : instructions) {
            if (c == 'L') {
                cdir = (cdir - 1 + 4) % 4; 
            } else if (c == 'R') {
                cdir = (cdir + 1) % 4; 
            } else {
                x += dir[cdir]; 
                y += dir[cdir + 1]; 
            }
        }
        
        return !(cdir == 0 && x != 0 && y != 0); 
        
    }
};
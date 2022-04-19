// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0;  
        array<int, 5> dirs{0, 1, 0, -1, 0};  
        int x = 0; 
        int y = 0; 
        
        for (char c : instructions) {
            if (c == 'G') {
                x += dirs[dir]; 
                y += dirs[dir + 1]; 
            } else if (c == 'L') {
                --dir; 
                dir = (4 + dir)%4; 
            } else if (c == 'R') {
                ++dir; 
                dir = dir % 4; 
            }
        }
        
        return (x == 0 && y == 0) || dir != 0; 
        
        
    }
};
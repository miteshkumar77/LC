// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle = ((double)minutes/60) * 360;
        double hour_angle = ((double)hour * 30) + ((double)minutes/60) * 30;
        
        double angle = abs(min_angle - hour_angle); 
        angle = min(angle, 360 - angle); 
        return angle; 
    }
};
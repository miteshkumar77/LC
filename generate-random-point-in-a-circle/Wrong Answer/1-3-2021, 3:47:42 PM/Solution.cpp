// https://leetcode.com/problems/generate-random-point-in-a-circle

class Solution {
public:
    Solution(double radius, double x_center, double y_center) : x_c(x_center), y_c(y_center), rad(radius) {}
    
    vector<double> randPoint() {
        double dist = rad * ((double)rand() / RAND_MAX);
        double angle = 2 * M_PI * ((double)rand() / RAND_MAX);
        return {dist * cos(angle) + x_c, dist * sin(angle) + y_c};     
    }
    
    double x_c;
    double y_c;
    double rad;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
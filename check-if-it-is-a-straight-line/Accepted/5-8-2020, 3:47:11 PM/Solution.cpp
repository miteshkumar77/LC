// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair<int, int> slope_i = slope(coordinates[0], coordinates[1]); 
        for (int i = 2; i < coordinates.size(); ++i) {
            if (slope_i != slope(coordinates[0], coordinates[i])) {
                return false; 
            }
        }
        
        return true; 
    }
    
    pair<int, int> slope(vector<int>& c1, vector<int>& c2) {
        int num = c1[0] - c2[0];
        int den = c1[1] - c2[1]; 
        int gcd = __gcd(num, den); 
        pair<int, int> frac((int)(num/gcd), (int)(den/gcd)); 
        if (frac.first == 0) {
            frac.second = 1; 
        } else if (frac.second == 0) {
            frac.first = 1; 
        }
        
        return frac; 
    }
};
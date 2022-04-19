// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int area(vector<int> const& r) {
        return (r[2] - r[0]) * (r[3] - r[1]);
    }
    
    int overlap(vector<int> const& r1, vector<int> const& r2) {
        return max(0, -1 * (max(r1[0], r2[0]) - min(r1[2], r2[2]))) * max(0, -1 * (max(r1[1], r2[1]) - min(r1[3], r2[3])));    
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        vector<int> r1{ax1, ay1, ax2, ay2};
        vector<int> r2{bx1, by1, bx2, by2};
        return area(r1) + area(r2) - overlap(r1, r2);
    }
};
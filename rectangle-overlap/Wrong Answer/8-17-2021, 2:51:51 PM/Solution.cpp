// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool check_between(int L, int c1, int c2, int R) {
        return (c1 > L && c1 < R) || (c2 > L && c2 < R);
    }
    
    bool check(vector<int> const& r1, vector<int> const& r2) {
        int vertical_left_1 = r1[0];
        int vertical_right_1 = r1[2];
        int vertical_left_2 = r2[0];
        int vertical_right_2 = r2[2];
        int horizontal_bot_1 = r1[1];
        int horizontal_top_1 = r1[3];
        int horizontal_bot_2 = r2[1];
        int horizontal_top_2 = r2[3];
        bool vert_overlap = check_between(vertical_left_1, vertical_left_2, vertical_right_2, vertical_right_1);
        bool horiz_overlap = check_between(horizontal_bot_1, horizontal_bot_2, horizontal_top_2, horizontal_top_1);
        return vert_overlap && horiz_overlap;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return check(rec1, rec2);
    }
};
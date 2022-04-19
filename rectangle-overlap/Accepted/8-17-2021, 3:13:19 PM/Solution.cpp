// https://leetcode.com/problems/rectangle-overlap

class Solution {
public:
    bool check_between(int L, int c1, int c2, int R, bool cont=true) {
        return (L < c1 && R > c1) || (L < c2 && R > c2) || (cont && check_between(c1, L, R, c2, false));
    }
    
    
    
    bool check(vector<int> const& r1, vector<int> const& r2) {
        if (r1 == r2) return true;
        int vertical_left_1 = r1[0];
        int vertical_right_1 = r1[2];
        int vertical_left_2 = r2[0];
        int vertical_right_2 = r2[2];
        int horizontal_bot_1 = r1[1];
        int horizontal_top_1 = r1[3];
        int horizontal_bot_2 = r2[1];
        int horizontal_top_2 = r2[3];
        bool vert = check_between(vertical_left_1, vertical_left_2, vertical_right_2, vertical_right_1);
        bool horiz = check_between(horizontal_bot_1, horizontal_bot_2, horizontal_top_2, horizontal_top_1);
        if (vertical_left_1 == vertical_left_2 && vertical_right_1 == vertical_right_2) {
            return horiz;
        } else if (horizontal_bot_1 == horizontal_bot_2 && horizontal_top_1 == horizontal_top_2) {
            return vert;
        }
        return horiz && vert;
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return check(rec1, rec2);
    }
};
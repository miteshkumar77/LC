// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        
        for (int i : asteroids) {
            if (i > 0) {
                stk.push_back(i);
            } else {
                int m = -1 * i;
                while(stk.size() != 0 && stk.back() > 0 && stk.back() < m) {
                    stk.pop_back();
                }
                if (stk.size() != 0 && stk.back() == m) {
                    stk.pop_back();
                } else if (stk.size() != 0 && stk.back() < m) {
                    stk.push_back(i);
                }
            }
        }
        return stk;
    }
};
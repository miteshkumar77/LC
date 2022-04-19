// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        
        for (int i : asteroids) {
            if (i > 0) {
                stk.push_back(i);
            } else {
                int a = -1 * i;
                bool busted = false;
                while(stk.size() != 0 && stk.back() > 0 && a >= stk.back()) {
                    if (stk.back() == a) {
                        busted = true;
                        stk.pop_back();
                        break;
                    }
                    stk.pop_back();
                }
                
                if (!busted && (stk.size() == 0 || stk.back() < 0)) {
                    stk.push_back(i);
                }
            }
        }
        return stk;
    }
};
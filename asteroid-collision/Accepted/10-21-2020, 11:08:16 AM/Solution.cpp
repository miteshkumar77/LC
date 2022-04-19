// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int a : asteroids) {
            bool destroyed = false;
            while(!ans.empty() && ans.back() > 0 && a < 0) {
                if (-1 * a <= ans.back()) {
                    destroyed = true;
                    if (-1 * a == ans.back()) {
                        ans.pop_back();
                    }
                    break;
                }
                ans.pop_back();
            }
            if (!destroyed) ans.push_back(a);
        }
        return ans;
    }
};
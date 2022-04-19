// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<bool> survives(asteroids.size(), true); 
        
        stack<int> stk_max; 
        int idx = 0; 
        for (int a : asteroids) {
            if (a > 0) {
                if (stk_max.empty() || a >= stk_max.top()) {
                    stk_max.push(a); 
                }
            } else {
                if (!stk_max.empty()) {
                    if (stk_max.top() > abs(a)) {
                        survives[idx] = false; 
                    } else if (stk_max.top() == abs(a)) {
                        survives[idx] = false; 
                        stk_max.pop(); 
                    } else {
                        stk_max = stack<int>(); 
                    }
                }
            }
            
            ++idx; 
        }
        
        
        stack<int> stk_min; 
        
        for (int i = (signed int)asteroids.size() - 1; i >= 0; --i) {
            int a = asteroids[i]; 
            if (a < 0) {
                if (stk_min.empty() || a <= stk_min.top()) {
                    stk_min.push(a); 
                }
            } else {
                if (!stk_min.empty()) {
                    if (stk_min.top() < -a) {
                        survives[i] = false; 
                    } else if (stk_min.top() == -a) {
                        survives[i] = false; 
                        stk_min.pop(); 
                    } else {
                        stk_min = stack<int>(); 
                    }
                }
            }
        }
        
        vector<int> ans; 
        for (int i = 0; i < survives.size(); ++i) {
            if (survives[i]) {
                ans.push_back(asteroids[i]); 
            }
        }
        
        return ans; 
        
    }
};
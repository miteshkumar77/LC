// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> d; 
        for (int i = 0; i < asteroids.size(); ++i) {
            int ast = asteroids[i]; 
            
            if (ast > 0) {
                d.push_back(ast); 
            } else {
                bool flag = false; 
                while(!d.empty() && d.back() > 0) {
                    if (d.back() > -ast) {
                        flag = true; 
                        break;  
                    } else if (d.back() == -ast) {
                        d.pop_back(); 
                        flag = true; 
                        break; 
                    } else {
                        d.pop_back(); 
                    }
                }
                if (!flag) {
                    d.push_back(ast); 
                }
            }
        }
        return d; 
        
    }
};
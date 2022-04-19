// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<bool> survives(asteroids.size(), true); 
        
        int max_sf = 0; 
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > max_sf) {
                max_sf = asteroids[i]; 
            } else if (asteroids[i] < 0) {
                if ((-1 * asteroids[i]) > max_sf) {
                    max_sf = 0; 
                } else if (-1 * asteroids[i] == max_sf) {
                    max_sf = 0; 
                    survives[i] = false; 
                } else {
                    survives[i] = false; 
                }
            }
        }
        
        
        int min_sf = 0; 
        for (int i = (signed int)asteroids.size() - 1; i >= 0; --i) {
            if (asteroids[i] < min_sf) {
                min_sf = asteroids[i]; 
            } else if (asteroids[i] > 0) {
                if ((-1 * asteroids[i]) < min_sf) {
                    min_sf = 0; 
                } else if ((-1 * asteroids[i]) == min_sf) {
                    min_sf = 0; 
                    survives[i] = false; 
                } else {
                    survives[i] = false; 
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
// https://leetcode.com/problems/meeting-scheduler

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        int s1 = 0; 
        int s2 = 0; 
        while(s1 < slots1.size() && s2 < slots2.size()) {
            // cout << s1 << ' ' << s2 << endl; 
            int min1 = slots1[s1][0]; int max1 = slots1[s1][1]; 
            int min2 = slots2[s2][0]; int max2 = slots2[s2][1]; 

            
            
            int overlap = min(max1, max2) - max(min1, min2); 
            if (overlap >= duration) {
                return vector<int>{max(min1, min2), max(min1, min2) + duration}; 
            }
            
            if (max2 <= max1) {
                ++s2; 
            } else {
                ++s1; 
            }
        }
        return vector<int>(); 
    }
};
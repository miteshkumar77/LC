// https://leetcode.com/problems/avoid-flood-in-the-city

class Solution {
public:
    typedef pair<int, int> pii; 
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_set<int> full; 
        map<int, int> earliest; 
        vector<int> ans (rains.size(), -1); 
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] != 0) {
                earliest[i] = rains[i]; 
            }
        }
        
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] != 0) {
                auto it = full.find(rains[i]); 
                if (it == full.end()) {
                    full.insert(rains[i]); 
                    earliest.erase(i); 
                    ans[i] = -1; 
                } else {
                    return vector<int>(); 
                }
            } else {
                auto it = earliest.begin(); 
                while(it != earliest.end() && full.find(it -> second) == full.end()) {
                    ++it; 
                }
                
                if (it == earliest.end()) {
                    ans[i] = 1; 
                } else {
                    ans[i] = it -> second; 
                    full.erase(it -> second);  
                    earliest.erase(it); 
                    
                }
            }
        }
        return ans; 
    }
};
// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> sts(1001, 0); 
        for (auto v : trips) {
            sts[v[1]] += v[0]; 
            sts[v[2]] -= v[0]; 
        }
        
        int car = 0; 
        for (int i : sts) {
            car += i; 
            if (car > capacity) {
                return false; 
            }
        }
        return true; 
        
        
    }
};
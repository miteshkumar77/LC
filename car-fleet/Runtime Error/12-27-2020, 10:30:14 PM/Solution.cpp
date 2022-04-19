// https://leetcode.com/problems/car-fleet

class Solution {
public:
    bool willCollideBefore(const array<int,2>& before, const array<int, 2>& after, int target) {
        return ((double)target - before[0])/before[1] <= ((double)target - after[0])/after[1];
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<array<int,2>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({position[i], speed[i]}); 
        }
        
        sort(pairs.begin(), pairs.end(), [](const array<int, 2>& a, const array<int,2>& b) -> bool {
            return a[0] > b[0];
        });
        
        int ans = 1;
        
        array<int, 2> after = pairs[0];
        
        for (int i = 1; i < n; ++i) {
            if (!willCollideBefore(pairs[i], after, target)) {
                ++ans;
                after = pairs[i];
            }
        }
        return ans;
    }
    
    
};
// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] <= b[1];  
        });
        
        int occupied = 0; 
        auto cmp = [&](vector<int>& a, vector<int>& b) -> bool {
            return a[2] >= b[2]; 
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> car(cmp); 
        for (auto v : trips) {
            
            while(!car.empty() && car.top()[2] <= v[1]) {
                // cout << car.top()[2] << endl; 
                occupied -= car.top()[0]; 
                car.pop(); 
            }
            car.push(v); 
            occupied += v[0]; 
            if (occupied > capacity) {
                return false; 
            }
        }
        
        return true; 
        
        
    }
};
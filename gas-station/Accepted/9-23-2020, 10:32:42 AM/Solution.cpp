// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(); 
        vector<int> pre(n); 
        pre[0] = gas[0] - cost[0]; 
        int sum = pre[0]; 
        for (int i = 1; i < n; ++i) {
            sum += gas[i] - cost[i]; 
            pre[i] = min(sum, pre[i - 1]); 
        }
        
        vector<int> suffmin(n); 
        sum = 0;
        int prevmin = 0;
        for (int i = n - 1; i >= 1; --i) {
            
            int dif = gas[i] - cost[i]; 
            sum += dif;
            if (dif + prevmin >= 0 && sum + pre[i - 1] >= 0) {
                return i;
            }
            prevmin = min(prevmin + dif, sum);
            // cout << prevmin << ' ' << i << endl; 
        }
        prevmin = min(prevmin + gas[0] - cost[0], sum + gas[0] - cost[0]); 
        // cout << prevmin << ' ' << 0 << endl;
        if (prevmin >= 0) {
            return 0; 
        }
        
        
        return -1;
        
    }
};
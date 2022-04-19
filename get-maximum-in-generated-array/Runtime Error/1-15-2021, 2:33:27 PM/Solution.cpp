// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    
    int getMaximumGenerated(int n) {
        vector<int> data(n + 1);
        data[0] = 0;
        data[1] = 1;
        
        int ans = 1;
        for (int i = 0; i <= n; ++i) {
            ans = max(ans, data[i]);
            if (i * 2 <= n && i * 2 >= 2) data[i * 2] = data[i];
            if (i * 2 + 1 <= n && i * 2 + 1 >= 2) data[i * 2 + 1] = data[i] + data[i+1];
        }
        
        return ans;
        
    }
};
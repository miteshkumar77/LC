// https://leetcode.com/problems/put-boxes-into-the-warehouse-i

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int m = boxes.size();
        vector<int> largest(n);
        largest[0] = warehouse[0];
        for (int i = 1; i < n; ++i) largest[i] = min(largest[i - 1], warehouse[i]);
        reverse(largest.begin(), largest.end());
        sort(boxes.begin(), boxes.end());
        int b = 0;
        int l = 0;
        int ans = 0;
        while(b < m && l < n) {
            if (largest[l] >= boxes[b]) {
                ++l;
                ++b;
                ++ans;
            } else {
                ++l;
            }
        }
        return ans;
        
    }
};
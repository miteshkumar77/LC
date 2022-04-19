// https://leetcode.com/problems/put-boxes-into-the-warehouse-ii

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        int b = boxes.size(); --b;
        int l = 0;
        int lv = INT_MAX;
        int r = warehouse.size(); --r;
        int rv = INT_MAX;
        int ans = 0;
        while(l <= r && b >= 0) {
            lv = min(lv, warehouse[l]);
            rv = min(rv, warehouse[r]);
            if (lv >= boxes[b]) {
                ++l;
                --b;
                ++ans;
            } else if (rv >= boxes[b]) {
                --r;
                --b;
                ++ans;
            } else {
                --b;
            }
        }
        return ans;
        
        
    }
};
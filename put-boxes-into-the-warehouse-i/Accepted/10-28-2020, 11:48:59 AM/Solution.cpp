// https://leetcode.com/problems/put-boxes-into-the-warehouse-i

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        cout << warehouse[0] << ' ';
        for (int i = 1; i < warehouse.size(); ++i) {
            warehouse[i] = min(warehouse[i - 1], warehouse[i]);
            cout << warehouse[i] << ' ';
            
        }cout << endl;
        int wptr = warehouse.size();
        
        int ans = 0;
        for (int i : boxes) {
            --wptr;
            while(wptr >= 0 && i > warehouse[wptr]) {
                --wptr;
            }
            if (wptr >= 0) {
                ++ans;
            } else {
                break;
            }
        }
        return ans;
    }
};
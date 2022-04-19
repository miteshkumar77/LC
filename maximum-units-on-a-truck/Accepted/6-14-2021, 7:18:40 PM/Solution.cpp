// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] > b[1];    
        });
        int units = 0;
        int total = 0;

        for (int i = 0; i < n && total < truckSize; ++i) {
            units += boxTypes[i][1] * min(boxTypes[i][0], truckSize - total);
            total += min(boxTypes[i][0], truckSize - total);
        }
        return units;
    }
};
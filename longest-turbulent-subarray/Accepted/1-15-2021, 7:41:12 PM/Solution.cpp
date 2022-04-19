// https://leetcode.com/problems/longest-turbulent-subarray

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int evenMax = 1;
        int oddMax = 1;
        int gans = 1;
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                if (!(arr[i] > arr[i-1])) {
                    evenMax = 0;
                }
                if (!(arr[i] < arr[i-1])) {
                    oddMax = 0;
                }
            } else {
                if (!(arr[i] > arr[i-1])) {
                    oddMax = 0;
                }
                if (!(arr[i] < arr[i-1])) {
                    evenMax = 0;
                }
            }
            ++evenMax;
            ++oddMax;
            gans = max(gans, max(evenMax, oddMax));
        }
        
        return gans;
    }
};
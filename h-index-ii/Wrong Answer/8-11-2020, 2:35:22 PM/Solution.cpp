// https://leetcode.com/problems/h-index-ii

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) {
            return 0; 
        }
        int L = 0; 
        int R = citations.size() - 1; 
        int ans = R; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (citations[mid] >= citations.size() - mid) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        return citations.size() - ans; 
    }
};
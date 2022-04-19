// https://leetcode.com/problems/maximum-distance-in-arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (vector<int>& v : arrays) {
            minimum = min(minimum, v[0]);
            maximum = max(maximum, v.back());
        }
        return maximum - minimum;
    }
};
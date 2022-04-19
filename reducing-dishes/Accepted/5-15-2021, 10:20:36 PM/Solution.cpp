// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int ans = 0;
        int sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (sum + ans + satisfaction[i] > ans) {
                ans = sum + ans + satisfaction[i];
                sum += satisfaction[i];
            }
        }
        return ans;
    }
};
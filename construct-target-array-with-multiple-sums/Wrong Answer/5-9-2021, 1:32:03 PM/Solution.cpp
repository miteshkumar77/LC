// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        sort(target.begin(), target.end());
        int sum = n;
        int original;
        int tmp;
        for (int i = 0; i < n; ++i) {
            original = 1;
            while(sum < target[i]) {
                tmp = sum;
                sum = sum - original + sum;
                original = tmp;
            }
            if (sum > target[i]) return false;
        }
        return true;
    }
};
// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        map<int, int> dp;
        dp[INT_MAX] = 0;
        int ans = 0;
        int num = 0;
        int prev = INT_MIN;
        for (int i : A) {
            num += i < prev;
            prev = i;
            dp[i] = 0;
            auto it = dp.find(i);
            it->second = next(it) -> second + 1;
            ans += it->second;
        }
        
        return ans == num;
    }
};
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans; ans.reserve(400000000);
        int sum = 0; 
        for (int i = 0; i < n - 1; ++i) {
            ans.push_back(i);
            sum += i; 
        }
        ans.push_back(-1 * sum); 
        return ans; 
    }
};
// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        set<int> se(nums.begin(), nums.end());
        vector<int> un(se.begin(), se.end());
        unordered_map<int,int> b4;
        for (int i = 0; i < un.size(); ++i) {
            b4[un[i]] = i;
        }
        int ans = 0;
        for (int i : nums) {
            // cout << i << ' ' << b4[i] << endl;
            ans += b4[i];
        }
        return ans;
    }
};
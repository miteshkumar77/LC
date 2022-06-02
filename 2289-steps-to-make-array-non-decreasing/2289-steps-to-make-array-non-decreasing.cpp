class Solution {
public:
    int totalSteps(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        vector<array<int, 2>> stk;
        int ans{0};
        for (int i : nums) {
            array<int, 2> p{i, 0};
            while(!stk.empty() && stk.back()[0] < p[0]) {
                p[1] = max(p[1] + 1, stk.back()[1]);
                stk.pop_back();
            }
            ans = max(ans, p[1]);
            stk.push_back(p);
        }
        return ans;
    }
};

/*
    [10,1,2,3,4,5,6,1,2,3]
    
    []
*/
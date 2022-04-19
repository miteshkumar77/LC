// https://leetcode.com/problems/array-nesting

class Solution {
public:
    vector<int> p;
    vector<int> s;
    
    int find(int n) {
        if (p[n] == -1) return n;
        p[n] = find(p[n]);
        return p[n];
    }
    
    bool onion(int a, int b) {
        int pa = find(a); int pb = find(b);
        if (pa == pb) return false;
        p[pa] = pb;
        s[pb] += s[pa];
        return true;
    }
    
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        p = vector<int> (n, -1);
        s = vector<int> (n, 1);
        for (int i = 0; i < n; ++i) {
            onion(nums[i], i);
            ans = max(ans, s[find(nums[i])]);
        }
        return ans;
    }
};
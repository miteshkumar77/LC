// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int s = 0;
        int ans = 0;
        for (int e = 0; e < nums.size(); ++e) {
            if (nums[e] == 0) {
                ans = max(ans, check(nums, s, e));
                s = e + 1;
            }
        }
        return max(ans, check(nums, s, nums.size()));
    }
    
    int check(const vector<int>& sub, int s, int e) {
        
        int ans = 0;
        unordered_map<int, int> seen;
        seen[1] = s - 1;
        int sign = 1;
        for (int i = s; i < e; ++i) {
            if (sub[i] < 0) sign = !sign;
            
            if (seen.find(sign) != seen.end()) {
                ans = max(ans, i - seen[sign]);
            }
            seen.insert(make_pair(sign, i));
        }
        // for (auto p : seen) cout << p.first << ' ' << p.second << endl;
        return ans;
    }
};
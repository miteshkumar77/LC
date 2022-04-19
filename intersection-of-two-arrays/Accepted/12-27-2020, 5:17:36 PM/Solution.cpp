// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> v(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int i : unordered_set<int>(nums2.begin(), nums2.end())) {
            if (v.find(i) != v.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
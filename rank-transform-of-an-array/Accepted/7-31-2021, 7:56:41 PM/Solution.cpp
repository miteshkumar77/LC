// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> nums(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        unordered_map<int,int> rank;
        int d = 1;
        for (int i = 0; i < n; ++i) {
            if (!rank.count(nums[i])) {
                rank[nums[i]] = d++;
            }
        }
        for (int& i : arr) i = rank[i];
        return arr;
    }
};
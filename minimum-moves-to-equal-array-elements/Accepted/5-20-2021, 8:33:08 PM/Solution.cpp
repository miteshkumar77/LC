// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        return accumulate(nums.begin(), nums.end(), 0) - n * (*min_element(nums.begin(), nums.end()));
    }
};
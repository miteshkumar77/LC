// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution {
public:
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string const& a, string const& b) {
            return a.length() < b.length() || (a.length() == b.length() && a < b);
        });
        reverse(nums.begin(), nums.end());
        return nums[k-1];
    }
};
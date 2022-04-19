// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution {
public:
    
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        nth_element(nums.begin(), nums.begin() + k-1, nums.end(), [](string const& a, string const& b) {
            return a.length() > b.length() || (a.length() == b.length() && a > b);
        });

        return nums[k-1];
    }
};
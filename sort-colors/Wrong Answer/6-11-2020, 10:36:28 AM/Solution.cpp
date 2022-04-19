// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0; 
        int R = nums.size() - 1;
        while(L < nums.size() && nums[L] == 0) { ++L; }
        while(R >= 0 && nums[R] == 2) { --R; }
        
        for (int i = L; i <= R; ++i) {
            cout << i << ' ' << R << endl; 
            if (nums[i] == 0) {
                swap(nums[i], nums[L++]); 
            } else if (nums[i] == 2) {
                swap(nums[i], nums[R--]); 
            }
        }
    }
};
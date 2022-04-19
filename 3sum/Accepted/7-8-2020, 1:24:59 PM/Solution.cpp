// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>(); 
        }
        sort(nums.begin(), nums.end()); 
        vector<vector<int> > ans; 
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
            int L = i + 1; 
            int R = nums.size() - 1; 
            
                while(L < R) {

                    if (nums[R] + nums[L] + nums[i] > 0) {
                        --R; 
                    } else if (nums[R] + nums[L] + nums[i] < 0) {
                        ++L; 
                    } else {
                        ans.push_back(vector<int>{nums[L], nums[R], nums[i]});
                        while(L < R) {
                            if (nums[L] == nums[L + 1]) {
                                ++L; 
                            } else if (nums[R] == nums[R - 1]) {
                                --R; 
                            } else {
                                break; 
                            }
                        }
                        ++L; 
                        --R; 
                    }
                }
            }
        }
        return ans; 
        
        
        // [-4, -1, -1, 0, 1, 2]
        
    }
};
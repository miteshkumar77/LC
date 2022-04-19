// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    Solution(vector<int>& nums) : orig(nums), cpy(vector<int>(nums.begin(), nums.end())) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> const& reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> const&  shuffle() {
        int n = cpy.size();
        for (int i = 0; i < n; ++i) {
            swap(cpy[i], cpy[rand() % (n - i) + i]);
        }
        return cpy;
    }
    vector<int> const& orig;
    vector<int> cpy;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums; 
        m_arr.swap(nums); 
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = m_arr.size(); 
        for (int i = 0; i < m_arr.size(); ++i) {
            swap(m_arr[rand() % (size--)], m_arr[size]);
        }
        return m_arr; 
    }
    
    vector<int> m_arr; 
    vector<int> original; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
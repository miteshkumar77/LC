// https://leetcode.com/problems/132-pattern

class Solution {
public:
    void erase(int num, map<int,int>& mp) {
        auto it = mp.find(num);
        --(it -> second);
        if (it -> second == 0) {
            mp.erase(it);
        }
    }
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        map<int,int> suff;
        
        for (int i = 1; i < n; ++i) {
            ++suff[nums[i]];
        }
        
        int minsf = nums[0];
        for (int i = 1; i < n; ++i) {
            auto it = suff.find(nums[i]);
            if (it != suff.begin()) {
                it = prev(it);
                if (it -> first > minsf) {
                    return true;
                }
            }
            minsf = min(nums[i], minsf);
            erase(nums[i], suff);
        }
        return false;
    }
};
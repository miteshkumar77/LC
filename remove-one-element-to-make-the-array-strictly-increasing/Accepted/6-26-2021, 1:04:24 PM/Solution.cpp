// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        nums.insert(nums.begin(), INT_MIN);
        nums.push_back(INT_MAX);
        int n = nums.size();
        vector<bool> inc(n, false);
        vector<bool> dec(n, false);
        inc[0] = true; dec[n-1] = true;
        for (int i = 1; i < n; ++i) {
            inc[i] = inc[i-1] && (nums[i] > nums[i-1]);
        }
        for (int i = n-2; i >= 0; --i) {
            dec[i] = dec[i+1] && (nums[i] < nums[i+1]);
        }
        //for (bool b : inc) cout << b << ' ';
        //cout << endl;
        //for (bool b : dec) cout << b << ' ';
        //cout << endl;
        for (int i = 1; i+1 < n; ++i) {
            if (inc[i-1] && dec[i+1] && nums[i-1] < nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
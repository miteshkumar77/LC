// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> P;
    NumArray(vector<int>& nums) : P(nums.size()+1, 0) {
        for (int i = 1; i <= nums.size(); ++i) {
            P[i] = P[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return P[right+1] - P[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
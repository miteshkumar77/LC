// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    
    vector<int> sums; 
    NumArray(vector<int>& nums) {
        sums = vector<int>(nums.size() + 1, 0); 
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i]; 
        }
    }
    
    int sumRange(int i, int j) {
        return (this -> sums)[j + 1] - (this -> sums)[i]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
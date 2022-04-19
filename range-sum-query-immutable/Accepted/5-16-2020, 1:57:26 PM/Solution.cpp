// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    
    vector<vector<int> > sums; 
    NumArray(vector<int>& nums) {
        int n = nums.size(); 
        sums = vector<vector<int> > (n + 1, vector<int>(n + 1, 0)); 
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                sums[i][j] = sums[i][j - 1] + nums[j - 1]; 
            }
        }
    }
    
    int sumRange(int i, int j) {
        return this -> sums[i + 1][j + 1]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sorter(nums, 0, nums.size() - 1);
        return nums; 
    }
    
    
    
    void sorter(vector<int>& A, int i, int j) {
        if (i >= j) {
            return;
        }
        int m = i + (j - i)/2; 
        sorter(A, i, m);
        sorter(A, m + 1, j);
        if (A[j] < A[m]) {
            swap(A[j], A[m]);
        }
        sorter(A, i, j - 1);
    }
};
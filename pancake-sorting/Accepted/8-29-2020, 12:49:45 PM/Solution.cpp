// https://leetcode.com/problems/pancake-sorting

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans; 
        for (int R = (signed int)A.size() - 1; R >= 0; --R) {
            int maxidx = getMaxIdx(A, R); 
            if (maxidx != R) {
                if (maxidx != 0) {
                    flip(A, maxidx); 
                }
                flip(A, R); 
                if (maxidx != 0) {
                    ans.push_back(maxidx + 1); 
                }
                ans.push_back(R + 1); 
            }
        }
        return ans; 
    }
    
    void flip(vector<int>& A, int R) {
        int L = 0; 
        while(L < R) {
            swap(A[L++], A[R--]); 
        }
    }
    int getMaxIdx(vector<int>& A, int R) {
        int idx = 0; 
        int val = A[0]; 
        
        for (int i = 1; i <= R; ++i) {
            if (A[i] > val) {
                val = A[i]; 
                idx = i; 
            }
        }
        return idx; 
    }
};
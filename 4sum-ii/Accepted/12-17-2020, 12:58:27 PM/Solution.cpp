// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        unordered_map<int,int> c1; 
        unordered_map<int,int> c2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++c1[A[i] + B[j]];
                ++c2[C[i] + D[j]];
            }
        }
        
        int ans = 0;
        
        for (auto p : c1) {
            int val = p.first;
            int ct = p.second;
            val *= -1;
            if (c2.find(val) != c2.end()) {
                ans += ct * c2[val];
            }
        }
        return ans;
        
    }
};
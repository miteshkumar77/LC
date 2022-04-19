// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = D.size();
        array<unordered_map<int,int>, 4> ct; fill(ct.begin(), ct.end(), unordered_map<int,int>()); 
        for (int i = 0; i < n; ++i) {
            ++ct[0][A[i]];
            ++ct[1][B[i]];
            ++ct[2][C[i]];
            ++ct[3][D[i]];
        }
        int ans = 0;
        for (auto p0 : ct[0]) {
            for (auto p1 : ct[1]) {
                for (auto p2 : ct[2]) {
                    int total = 0 - p0.first - p1.first - p2.first;
                    
                    if (ct[3].find(total) != ct[3].end()) {
                        ans += p0.second * p1.second * p2.second * ct[3][total];
                    }
                    
                }
            }
        }
        return ans;
    }
};
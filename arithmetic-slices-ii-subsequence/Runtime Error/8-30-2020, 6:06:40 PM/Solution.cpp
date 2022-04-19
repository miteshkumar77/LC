// https://leetcode.com/problems/arithmetic-slices-ii-subsequence

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, array<int, 2>>> prevdif(A.size()); 
        int ans = 0; 
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                prevdif[i].insert(make_pair(A[i] - A[j], array<int, 2>{0, 0})); 
                ++prevdif[i][A[i] - A[j]][0]; 
                if (prevdif[j].find(A[i] - A[j]) != prevdif[j].end()) {
                    prevdif[i][A[i] - A[j]][1] += prevdif[j][A[i] - A[j]][0] + prevdif[j][A[i] - A[j]][1]; 
                }
            }
            
            for (auto p : prevdif[i]) {
                ans += p.second[1]; 
            }
        }
        
        // for (int i = 0; i < A.size(); ++i) {
        //     cout << A[i] << ": "; 
        //     for (auto p : prevdif[i]) {
        //         cout << p.first << ": (" << p.second[0] << ", " << p.second[1] << "), "; 
        //     }
        //     cout << endl; 
        // }
        return ans; 
    }
};
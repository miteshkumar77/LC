// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> Act;
        unordered_map<int,int> Bct;
        unordered_map<int,int> DoubleCt;
        for (int i = 1; i <= 6; ++i) {
            Act[i] = 0;
            Bct[i] = 0;
            DoubleCt[i] = 0;
        }
        for (int i = 0; i < A.size(); ++i) {
            ++Act[A[i]];
            ++Bct[B[i]];
            if (A[i] == B[i]) {
                ++DoubleCt[A[i]];
            }
            
            
        }
        
        
        int ans = INT_MAX;
        for (int i : A) {
            if (Act[i] + Bct[i] - DoubleCt[i] == A.size()) {
                ans = min(ans, min(Act[i], Bct[i]) - DoubleCt[i]);
            } 
            break;
        }
        for (int i : B) {
            if (Act[i] + Bct[i] - DoubleCt[i] == A.size()) {
                ans = min(ans, min(Act[i], Bct[i]) - DoubleCt[i]);
            } 
            break;
        }
        ans = ans == INT_MAX?-1:ans;
        return ans;
    }
};
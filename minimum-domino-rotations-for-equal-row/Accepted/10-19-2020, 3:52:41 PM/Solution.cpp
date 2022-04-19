// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> Act;
        unordered_map<int,int> Bct;
        unordered_map<int,int> DoubleCt;
        for (int i = 0; i < A.size(); ++i) {
            ++Act[A[i]];
            ++Bct[B[i]];
            if (A[i] == B[i]) {
                ++DoubleCt[A[i]];
            }
            auto a = make_pair(A[i], 0);
            auto b = make_pair(B[i], 0);
            Act.insert(a);
            Act.insert(b);
            Bct.insert(a);
            Bct.insert(b);
            DoubleCt.insert(a);
            DoubleCt.insert(b);
        }
        
        
        int ans = INT_MAX;
        for (int i : A) {
            if (Act[i] + Bct[i] - DoubleCt[i] == A.size()) {
                ans = min(ans, min(Act[i], Bct[i]) - DoubleCt[i]);
            } 
        }
        ans = ans == INT_MAX?-1:ans;
        return ans;
    }
};
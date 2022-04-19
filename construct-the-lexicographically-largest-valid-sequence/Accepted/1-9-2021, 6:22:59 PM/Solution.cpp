// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int N = 2 * n - 1;
        vector<int> ans(N, 1);
        vector<bool> used(n + 1, false);
        int numUsed = 1;
        bool done = false;
        function<void(int)> bt = [&](int idx) -> void {
            if (numUsed == n) {
                done = true;
                return;
            }
            if (idx == N - 1) {
                return;
            }
            
            if (ans[idx] != 1) {
                bt(idx + 1);
                return;
            }
            
            for (int i = n; i >= 2; --i) {
                if (used[i]) continue;
                if (i + idx >= N) return;
                if (ans[idx] != 1 || ans[idx+i] != 1) continue;
                ans[idx] = i;
                ans[idx+i] = i;
                used[i] = true;
                ++numUsed;
                bt(idx + 1);
                if (done) return;
                ans[idx] = 1;
                ans[idx+i] = 1;
                used[i] = false;
                --numUsed;
            }
            bt(idx + 1);
        };
        bt(0);
        return ans;
    }
};
// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool solve(vector<int> ct) {
        int n = ct.size();
        for (int i = 0; i < n; ++i) {
            if (i * 2 >= n || ct[i] > ct[i*2]) return false;
            ct[i*2] -= ct[i];
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        int N = max(abs(*min_element(arr.begin(), arr.end())), abs(*max_element(arr.begin(), arr.end())));
        vector<int> pos(N+1, 0);
        vector<int> neg(N+1, 0);
        for (int i : arr) {
            if (i < 0) ++neg[-1 * i];
            else ++pos[i];
        }
        return solve(pos) && solve(neg);
    }
};
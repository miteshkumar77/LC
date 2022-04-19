// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool solve(vector<int> ct) {
        int n = ct.size();
        for (int i = 0; i < n/2; ++i) {
            if (ct[i*2] < ct[i]) return false;
            ct[i*2] -= ct[i];
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        int N = max(abs(*min_element(arr.begin(), arr.end())), abs(*max_element(arr.begin(), arr.end())));
        vector<int> pos(2 * (N+1) + 2, 0);
        vector<int> neg(2 * (N+1) + 2, 0);
        for (int i : arr) {
            if (i < 0) ++neg[-1 * i];
            else ++pos[i];
        }
        return solve(pos) && solve(neg);
    }
};
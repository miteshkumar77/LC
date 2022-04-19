// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool solve(map<int,int>& ct) {
        for (; !ct.empty(); ) {
            auto it = ct.find(ct.begin()->first * 2);
            if (it == ct.end()) return false;
            if (--it->second == 0) ct.erase(it);
            if (--ct.begin()->second == 0) ct.erase(ct.begin());
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> pos, neg;
        for (int i : arr) {
            if (i < 0) ++neg[-1 * i];
            else ++pos[i];
        }
        return solve(pos) && solve(neg);
    }
};
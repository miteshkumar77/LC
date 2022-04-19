// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        
        string sn = to_string(n);
        int l = sn.length();
        int swap_idx = l - 1;
        for (int i = l - 2; i >= 0; --i) {
            if (sn[swap_idx] < sn[i]) {
                swap_idx = i;
            }
            if (sn[swap_idx] > sn[i]) {
                for (int j = i + 1; j < l; ++j) {
                    if (sn[j] > sn[i] && sn[j] < sn[swap_idx]) {
                        swap_idx = j;
                    }
                }
                swap(sn[i], sn[swap_idx]);
                
                sort(sn.begin() + i + 1, sn.end());
                string smax = to_string(INT_MAX);
                if (l > smax.length() || (l == smax.length() && smax < sn)) {
                    return -1;
                }
                return stoi(sn);
            }
        }
        return -1;
    }
};
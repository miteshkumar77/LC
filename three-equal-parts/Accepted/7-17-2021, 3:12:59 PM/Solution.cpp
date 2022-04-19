// https://leetcode.com/problems/three-equal-parts

class Solution {
public:
    bool eq(vector<int>& a, vector<int>& b, vector<int>& c) {
        int i = a.size(); int j = b.size(); int k = c.size();
        if (i == 0 || j == 0 || k == 0) return 0;
        --i; --j; --k;
        while(i >= 0 || j >= 0 || k >= 0) {
            int ival = i < 0 ? 0 : a[i--];
            int jval = j < 0 ? 0 : b[j--];
            int kval = k < 0 ? 0 : c[k--];
            if (ival != jval || jval != kval) return false;
        }
        return true;
    }
    
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = accumulate(arr.begin(), arr.end(), 0);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) {
            int s = arr.size();
            // if (s % 3 != 0) return {-1,-1};
            return {s/3 - 1, 2 * (s/3)};
        }
        int end_z = 0;
        for (int i = n-1; i >= 0 && arr[i] == 0;--i, ++end_z);
        int o_ct = 0;
        int l_z = 0;
        for (int i = 0; i < n; ++i) {
            o_ct += arr[i];
            l_z = (arr[i] ? 0 : l_z + 1);
            if (l_z == end_z && o_ct == ones/3) {
                l_z = 0;
                o_ct = 0;
                for (int j = i+1; j < n; ++j) {
                    o_ct += arr[j];
                    l_z = (arr[j] ? 0 : l_z + 1);
                    if (o_ct == ones/3 && l_z == end_z) {
                        vector<int> a(arr.begin(), arr.begin() + i + 1);
                        vector<int> b(arr.begin() + i + 1, arr.begin() + j + 1);
                        vector<int> c(arr.begin() + j + 1, arr.end());
                        if (eq(a, b, c)) {
                            return {i, j+1};
                        } else {
                            return {-1, -1};
                        }
                    }
                }
            }
        }
        
        return {-1, -1};
    }
};
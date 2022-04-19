// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends

class Solution {
public:
    
    int f(vector<int>& v, int node) {
        if (v[node] == -1) {
            return node;
        }
        v[node] = f(v, v[node]);
        return v[node];
    }
    
    bool u(vector<int>& v, int a, int b) {
        int pa = f(v, a);
        int pb = f(v, b);
        if (pa == pb) return false;
        v[pa] = pb;
        return true;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());    
        vector<int> v(n, -1);
        int c = n;
        for (auto const& l : logs) {
            if (u(v, l[1], l[2])) {
                --c;
                if (c == 1) {
                    return l[0];
                }
            }
        }
        return -1;
    }
};
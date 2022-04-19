// https://leetcode.com/problems/zuma-game

class Solution {
public:
    int findMinStep(string board, string hand) {
        map<int, int> hd;
        char curr = '_';
        int ct = 0;
        list<array<int, 2>> bd;
        for (char c : board) {
            if (bd.empty() || bd.back()[0] != (int)c) {
                bd.push_back({(int)c, 0});
            }
            ++bd.back()[1];
        }
        for (char c : hand) {
            ++hd[(int)c];
        }
        int ans = findMin(bd, hd);
        return ans >= 1e9 ? -1 : ans;
    }
    
    int findMin(list<array<int, 2>>& bd, map<int, int>& hd) {
        list<array<int, 2>> cur;
        for (const auto& a : bd) {
            if (!cur.empty() && cur.back()[0] == a[0]) {
                cur.back()[1] += a[1];
            } else {
                cur.push_back(a);
            }
            if (cur.back()[1] == 0 || cur.back()[1] >= 3) {
                cur.pop_back();
            }
        }

        if (cur.size() == 0) {
            return 0;
        }
        int ans = 1e9;
        for (auto it = cur.begin(); it != cur.end(); ++it) {
            int val = (*it)[0]; int ct = (*it)[1];
            if (hd.count(val) && 3 - ct <= hd[val]) {
                hd[val] -= 3 - ct;
                it = cur.erase(it);
                if (hd[val] == 0) hd.erase(val);
                ans = min(ans, 3 - ct + findMin(cur, hd));
                hd[val] += 3 - ct;
                it = cur.insert(it, {val, ct});
                //cout << (char)val << ' ' << ct << endl;
            }
        }
        return ans;
    }
    
};
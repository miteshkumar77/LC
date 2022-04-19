// https://leetcode.com/problems/longest-substring-of-one-repeating-character

class Solution {
public:
    void add(map<int,int>& mp, map<int,int>& len, pair<int,int> p) {
        ++len[p.second-p.first+1];
        mp[p.first] = p.second;
    }
    // last element that is less than or equal to val
    map<int,int>::iterator mylb(map<int,int>& mp, int val) {
        auto it = mp.lower_bound(val);
        if (it->first > val) {
            return prev(it);
        }
        return it;
    }
    void del(map<int,int>& mp, map<int,int>& len, pair<int,int> p) {
        if (--len[p.second - p.first+1] == 0) {
            len.erase(p.second - p.first + 1);
        }
        mp.erase(p.first);
    }
    vector<int> longestRepeating(string s, string qC, vector<int>& qI) {
        map<int,int> mp;    
        int n = s.length();
        int prev_p = 0;
        map<int, int> len;
        for (int i = 1; i <= n; ++i) {
            if (i == s.length() || s[i] != s[prev_p]) {
                mp[prev_p] = i-1;
                ++len[i-prev_p];
                prev_p = i;
            }
        }
        int k = qC.length();
        vector<int> ans(k);
        /*
            for (auto p : mp) {
                cout << "[" << p.first << ' ' << p.second << "] ";
            }
            cout << endl;
        */
        for (int q = 0; q < qC.length(); ++q) {
            if (s[qI[q]] != qC[q]) {
                auto split = mylb(mp, qI[q]);
                pair<int,int> left = {split->first, qI[q]-1};
                pair<int,int> right = {qI[q]+1, split->second};
                del(mp, len, *split);
                if (left.first <= left.second) {
                    add(mp, len, left);
                }
                if (right.first <= right.second) {
                    add(mp, len, right);
                }
                pair<int,int> add_p = {qI[q], qI[q]};
                s[qI[q]] = qC[q];
                if (qI[q] != 0 && s[qI[q]] == s[qI[q]-1]) {
                    auto it = mylb(mp, add_p.first);
                    add_p.first = it->first;
                    del(mp, len, *it);
                }
                if (qI[q] != n-1 && s[qI[q]] == s[qI[q]+1]) {
                    auto it = mp.upper_bound(add_p.first);
                    add_p.second = it->second;
                    del(mp, len, *it);
                }
                add(mp, len, add_p);
            }
            /*
            for (auto p : mp) {
                cout << "[" << p.first << ' ' << p.second << "] ";
            }
            cout << endl;
            */
            ans[q] = prev(len.end())->first;
        }
        return ans;
    }
};
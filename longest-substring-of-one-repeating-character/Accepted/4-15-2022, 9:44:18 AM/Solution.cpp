// https://leetcode.com/problems/longest-substring-of-one-repeating-character

class Solution {
private:
    map<int,int> ints;
    map<int,int> lens;
    void add(int l, int r) {
        ints[l] = r;
        ++lens[r - l + 1];
    }
    
    void rem(int l, int r) {
        ints.erase(l);
        if (--lens[r - l + 1] == 0)
            lens.erase(r - l + 1);
    }
    
    pair<int,int> get_split(int left) {
        auto tmp = ints.lower_bound(left);
        return ((tmp != ints.end()) && (tmp->first == left)) ? (*tmp) : (*prev(tmp));
    }
    void print_ints() {
        for (auto p : ints) {
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << endl;
    }
public:
    vector<int> longestRepeating(string s, string qC, vector<int>& qI) {
        int f = 0;
        int n = s.length();
        int Q = qC.size();
        for (int i = 1; i <= n; ++i) {
            if (i == n || (s[i] != s[f])) {
                add(f, i-1);
                f = i;
            }
        }
        // print_ints();
        vector<int> ans(Q);
        for (int q = 0; q < Q; ++q) {
            if (s[qI[q]] != qC[q]) {
                auto split = get_split(qI[q]);
                // cout << "split:" << qI[q] << " [" << split.first << ' ' << split.second << "] ";
                rem(split.first, split.second);
                pair<int,int> left_split{split.first, qI[q]-1};
                pair<int,int> right_split{qI[q]+1, split.second};
                pair<int,int> add_int{qI[q], qI[q]};
                s[qI[q]] = qC[q];
                if (left_split.first <= left_split.second) {
                    add(left_split.first, left_split.second);
                } else if (qI[q] > 0 && s[qI[q]] == s[qI[q]-1]) {
                    auto left_join = get_split(qI[q]-1);
                    add_int.first = left_join.first;
                    rem(left_join.first, left_join.second);
                }
                
                if (right_split.first <= right_split.second) {
                    add(right_split.first, right_split.second);
                } else if (qI[q] + 1 < n && s[qI[q]] == s[qI[q]+1]) {
                    auto right_join = (*ints.upper_bound(qI[q]));
                    add_int.second = right_join.second;
                    rem(right_join.first, right_join.second);
                }
                add(add_int.first, add_int.second);
            }
            ans[q] = prev(lens.end())->first;
            // cout << ans[q] << "[ " << s << " ]: ";
            // print_ints();
        }
        return ans;
    }
};
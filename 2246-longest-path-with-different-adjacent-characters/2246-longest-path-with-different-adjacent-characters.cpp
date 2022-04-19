class Solution {
public:
    pair<int,int> solve(vector<vector<int>>& tree, int node, string const& s) {
        int longest_thru = 1;    
        int longest_path = 1;
        multiset<int> l2;
        for (int child : tree[node]) {
            auto [c_thru, c_longest] = solve(tree, child, s);
            longest_path = max(longest_path, c_longest);
            if (s[child] != s[node]) {
                longest_thru = max(longest_thru, c_thru + 1);
                l2.insert(c_thru);
                if (l2.size() > 2) {
                    l2.erase(l2.begin());
                }
            }
        }
        if (l2.size() == 2) {
            vector<int> l2a(l2.begin(), l2.end());
            longest_path = max(longest_path, l2a[0] + 1 + l2a[1]);
        }
        longest_path = max(longest_path, longest_thru);
        return {longest_thru, longest_path};
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            tree[parent[i]].push_back(i);
        }
        return solve(tree, 0, s).second;
    }
};
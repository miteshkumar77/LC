class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<array<int, 2>> v;
        for (char c : s) {
            if (!v.empty() && c == v.back()[0]) {
                ++v.back()[1];
            } else {
                v.push_back({c, 1});
            }
            if (v.back()[1] == k) {
                v.pop_back();
            }
        }
        string ans;
        for (auto & p : v) {
            while(p[1]-- > 0) {
                ans.push_back((char)p[0]);
            }
        }
        return ans;
    }
};
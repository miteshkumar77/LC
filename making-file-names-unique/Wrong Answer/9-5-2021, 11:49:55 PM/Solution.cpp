// https://leetcode.com/problems/making-file-names-unique

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> v;
        int n = names.size();
        v.reserve(n);
        for (string const& s : names) {
            if (!mp.count(s)) {
                v.push_back(s);
                mp[s] = 0;
            } else {
                ++mp[s];
                while(mp.count(s + "(" + to_string(mp[s]) + ")")) {
                    ++mp[s];
                }
                v.push_back(s + "(" + to_string(mp[s]) + ")");
            }
        }
        return v;
    }
};
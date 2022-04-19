// https://leetcode.com/problems/find-duplicate-file-in-system

class Solution {
public:
    vector<array<string, 2>> parseContents(const string& path) {
        // cout << "---" << path << "---" << endl;
        size_t n = path.find(" ");
        string loc = path.substr(0, n);
        vector<array<string, 2>> ret;
        size_t next;
        // cout << n << endl;
        while(n != string::npos) {
            next = path.find(" ", n + 1);
            // if (next == string::npos) {
                // cout << n << ": NPOS" << endl;
            // }
            string obj = path.substr(n + 1, next == string::npos ? next : next - n - 1);
            string fname = loc + "/" + obj.substr(0, obj.find('('));
            size_t sc = obj.find("(") + 1;
            size_t ec = obj.find(")", sc);
            string content = obj.substr(sc, ec - sc);
            ret.push_back({fname, content});
            n = next;
            // cout << fname << "| |" << content << endl;
        }
        return ret;
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content;
        for (const auto& s : paths) {
            for (const auto& p : parseContents(s)) {
                content[p[1]].push_back(p[0]);
            }
        }
        vector<vector<string>> ret;
        ret.reserve(content.size());
        for (const auto& p : content) {
            ret.push_back(p.second);
        }
        return ret;
    }
};
















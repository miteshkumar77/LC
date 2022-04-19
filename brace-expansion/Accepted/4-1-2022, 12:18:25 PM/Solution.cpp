// https://leetcode.com/problems/brace-expansion

class Solution {
public:
    pair<vector<string>, int> expand(string const& exp, int s) {
        vector<vector<string>> ret{{""}};
        for (int i = s; i <= exp.length(); ++i) {
           if (i == exp.length() || exp[i] == '}') {
                vector<string> comb;
                for (auto & v : ret) {
                    for (auto & pref : v) {
                        comb.push_back(pref);
                    }
                }
                return {comb, i};
            } else if (exp[i] <= 'z' && exp[i] >= 'a') {
                for (string& pref : ret.back()) {
                    pref.push_back(exp[i]);
                }
            } else if (exp[i] == ',') {
                ret.push_back({""});
            } else if (exp[i] == '{') {
                auto [rcomb, rs] = expand(exp, i+1);
                i = rs;
                vector<string> nb;
                for (auto fir : ret.back()) {
                    for (auto sec : rcomb) {
                        nb.push_back(fir + sec);
                    }
                }
                ret.back() = nb;
            }
        }
        return {vector<string>(), 0};
    }
    
    vector<string> expand(string expression) {
        auto tmp = expand(expression, 0).first;
        auto tmp2 = set<string>(tmp.begin(), tmp.end());
        return vector<string>(tmp2.begin(), tmp2.end());
    } 
    
};
// https://leetcode.com/problems/number-of-atoms

class Solution {
public:
    string countOfAtoms(string formula) {
        
        function<pair<unordered_map<string,int>, int>(int)> bt = [&](int i) -> pair<unordered_map<string,int>, int> {
            string element;
            string count;
            unordered_map<string,int> curr;
            
            for (int c = i; c < formula.length(); ++c) {
                if (formula[c] == '(') {
                    if (element != "") {
                        count = count==""?"1":count;
                        curr[element] += stoi(count);
                        count = "";
                        element = "";
                    }
                    
                    auto [nmap, nidx] = bt(c + 1);
                    for (auto p : nmap) {
                        curr[p.first] += p.second;
                    }
                    c = nidx;
                } else if (formula[c] == ')') {
                    if (element != "") {
                        count = count==""?"1":count;
                        curr[element] += stoi(count);
                        count = "";
                        element = "";
                    }
                    
                    ++c;
                    while(c < formula.length() && formula[c] <= '9' && formula[c] >= '0') {
                        count.push_back((char)(formula[c++]));
                    }
                    // cout << count << endl;
                    count = count==""?"1":count;
                    int intcount = stoi(count);
                    for (auto p : curr) {
                        curr[p.first] *= intcount;
                    }
                    return make_pair(curr, c - 1);
                    
                } else if (formula[c] >= 'A' && formula[c] <= 'Z') {
                    if (element != "") {
                        count = count==""?"1":count;
                        curr[element] += stoi(count);
                        count = "";
                        element = "";
                    }
                    element += formula[c];
                } else if (formula[c] >= 'a' && formula[c] <= 'z') {
                    element += formula[c];
                } else {
                    count += formula[c];
                }
            }
            
            if (element != "") {
                count = count==""?"1":count;
                curr[element] += stoi(count);
                count = "";
                element = "";
            }
            
            return make_pair(curr, formula.length());
            
        };
        
        auto res = bt(0).first;
        auto mp = map<string, int>(res.begin(), res.end());
        string ans;
        for (auto p : mp) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        
        return ans;
        
        
    }
};
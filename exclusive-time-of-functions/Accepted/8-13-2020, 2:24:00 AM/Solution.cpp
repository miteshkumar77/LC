// https://leetcode.com/problems/exclusive-time-of-functions

class Solution {
public:
    
    
    vector<string> gets(string& s) {
        string t = ""; 
        s += ':'; 
        vector<string> ans; 
        for (char c : s) {
            if (c == ':') {
                ans.push_back(t); 
                t = ""; 
            } else {
                t += c; 
            }
        }
        return ans; 
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<array<int, 2>> stk; 
        vector<int> ans(n, 0); 
        
        for (string log : logs) {
            vector<string> g = gets(log); 
            if (g[1] == "start") {
                array<int, 2> nxt {stoi(g[0]), stoi(g[2])};
                if (!stk.empty()) {
                    ans[stk.top()[0]] += (nxt[1] - stk.top()[1]); 
                }
                
                stk.push(nxt); 
            }
            
            if (g[1] == "end") {
                
                array<int, 2> nxt {stoi(g[0]), stoi(g[2])};
                ans[stk.top()[0]] += (nxt[1] - stk.top()[1] + 1); 
                stk.pop(); 
                if (!stk.empty()) {
                    stk.top()[1] = nxt[1] + 1; 
                }
            }
        }
        
        return ans; 
    }
};
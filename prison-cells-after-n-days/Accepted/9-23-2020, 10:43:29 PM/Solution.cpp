// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        string cur;
        for (int i : cells) {
            cur += (char)(i + '0'); 
        }
        
        
        bool truncated = true;
        unordered_map<string,int> seen;
        seen[cur] = 0;
        for (int i = 1; i <= N; ++i) {
            go(cur);
            if (seen.find(cur) != seen.end()) {
                N = N - i;
                N = N % (i - seen[cur]) - 1;
                truncated = false;
                break;
            }
            seen[cur] = i; 
        }
        // cout << cur << endl; 
        if (!truncated) {
            for (int i = 0; i <= N; ++i) {
                go(cur);
            }
        }
        for (int i = 0; i < cur.length(); ++i) {
            cells[i] = cur[i] == '1'; 
        }
        return cells;
        
    }
    
    
    void go(string& s) {
        int n = s.length();
        string next;
        next += '0'; 
        for (int i = 1; i < n - 1; ++i) {
            if (s[i - 1] == s[i + 1]) {
                next += '1';
            } else {
                next += '0'; 
            }
        }
        next += '0';
        s = next;
    }
};
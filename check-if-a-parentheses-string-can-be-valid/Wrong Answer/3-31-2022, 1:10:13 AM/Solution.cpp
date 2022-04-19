// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 == 1) return false;
        vector<int> need(n, 0);
        int acc = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1' && (acc += (s[i] == '(' ? 1 : -1)) < 0) {
                need[i] = 1;
            }
        }
        
        for (int i = n-1; i >= 0; --i) {
            if (locked[i] == '1' && (acc += (s[i] == ')' ? 1 : -1)) < 0) {
                need[i] = 1;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '0') {
                q.push(i);
            } else if (need[i] && s[i] == ')') {
                if (q.empty()) { 
                    return false;
                }
                locked[q.front()] = '1';
                q.pop();
            }
        }
        q = queue<int>();
        for (int i = n-1; i >= 0; --i) {
            if (locked[i] == '0') {
                q.push(i);
            } else if (need[i] && s[i] == '(') {
                if (q.empty()) {
                    return false;
                }
                locked[q.front()] = '1';
                q.pop();
            }
        }
        return true;
        /*
        int num_unlocked = 0;
        for (int i = 0; i < n; ++i) num_unlocked += (locked[i] == '0');
        return num_unlocked % 2 == 0;
        */
        
    }
};
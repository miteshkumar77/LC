// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string S) {
        string ans = ""; 
        array<int, 26> ct{0}; 
        for (char c : S) {
            ++ct[c - 'a'];
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char> >, less<pair<int, char> >> pq; 
        for (int i = 0; i < 26; ++i) {
            if (ct[i] != 0) {
                pq.push(make_pair(ct[i], (char)(i + 'a')));
            }
        }
        while(!pq.empty()) {
            pair<int, char> t1 = pq.top(); pq.pop(); 
            if (ans.length() != 0 && ans.back() == t1.second) {
                if (pq.empty()) {
                    return ""; 
                }
                pair<int, char> t2 = pq.top(); pq.pop(); 
                --t2.first;
                ans += t2.second; 
                if (t2.first > 0) {
                    pq.push(t2); 
                }
                pq.push(t1);
            } else {
                --t1.first;
                ans += t1.second;
                if (t1.first > 0) {
                    pq.push(t1); 
                }
            }
        }
        return ans; 
    }
};
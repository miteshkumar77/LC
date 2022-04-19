// https://leetcode.com/problems/orderly-queue

class Solution {
public:
    string orderlyQueue(string s, int k) {
        priority_queue<char, vector<char>, less<char>> pq;
        
        int n = s.length();
        string ans;
        for (char c : s) {
            pq.push(c);
            if (pq.size() == k) {
                ans.push_back(pq.top()); pq.pop();
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top()); pq.pop();
        }
        int i = 0;
        int si = 0;
        for (int j = 1; j < n; ++j) {
            if (s[j] < s[i]) {
                si = j;
                i = j;
            } else if (s[j] == s[i]) {
                ++i;
            } else {
                i = si;
            }
        }
        return ans.substr(i) + ans.substr(0, i);
        
    }
};



















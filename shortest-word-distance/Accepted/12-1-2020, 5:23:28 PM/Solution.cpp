// https://leetcode.com/problems/shortest-word-distance

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> p1; 
        vector<int> p2; 
        int k = 0;
        for (string s : words) {
            if (s == word1) {
                p1.push_back(k); 
            } else if (s == word2) {
                p2.push_back(k);
            }
            ++k;
        }
        
//         for (int x : p1) cout << x << ' ';
//         cout << endl;
        
        
//         for (int x : p2) cout << x << ' ';
//         cout << endl;
        
        int ans = INT_MAX;
        int i = 0;
        int j = 0;
        while(i < p1.size() && j < p2.size()) {
            ans = min(ans, abs(p2[j] - p1[i]));
            if (p1[i] < p2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
};
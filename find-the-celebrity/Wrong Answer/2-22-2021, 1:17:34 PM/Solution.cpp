// https://leetcode.com/problems/find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> cands; 
        for (int i = 0; i < n; ++i) {
            cands.insert(i); 
        }
        vector<int> degree(n, 0); 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (!knows(i, j)) {
                    cands.erase(j);
                } else {
                    ++degree[j];
                    cands.erase(i);
                }
                if (cands.size() == 1 && degree[*cands.begin()] == n - 1) {
                    return *cands.begin(); 
                }
            }
        }
        return -1;
        
    }
};
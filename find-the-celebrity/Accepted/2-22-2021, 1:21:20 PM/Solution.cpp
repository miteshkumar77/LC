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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (!knows(i, j)) {
                    cands.erase(j);
                } else {
                    cands.erase(i);
                }
                if (cands.size() == 0) {
                    return -1;
                }
                if (cands.size() == 1) {
                    int c = *cands.begin(); 
                    for (int x = 0; x < n; ++x) {
                        if (x != c && (knows(c, x) || !knows(x, c))) {
                            return -1;
                        }
                    }
                    return c;
                }
            }
        }
        return -1;
        
    }
};
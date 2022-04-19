// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<set<int> > members(N + 1, set<int>()); 
        
        for (vector<int> tr : trust) {
            members[tr[0]].insert(tr[1]); 
            cout << tr[0] << ' ' << tr[1] << endl; 
        }
        
        bool found = false; 
        int candidate = -1; 
        
        for (int i = 1; i < members.size(); ++i) {
            if (members[i].empty()) {
                if (found) {
                    return -1; 
                } else {
                    candidate = i; 
                    found = true; 
                }
            }
        }
        
        for (int i = 1; i < members.size(); ++i) {
            if (i == candidate) {
                if (members[i].find(i) != members[i].end()) {
                    return -1; 
                }
            } else {
                if (members[i].find(candidate) == members[i].end()) {
                    return -1; 
                }
            }
        }
        
        return candidate; 
        
    }
};
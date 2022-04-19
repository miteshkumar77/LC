// https://leetcode.com/problems/path-crossing

class Solution {
    typedef pair<int, int> pii; 
public:
    bool isPathCrossing(string path) {
        set<pii> p; 
        pii init(0, 0); 
        p.insert(init); 
        array<pii, 26> dirs; 
        dirs['N' - 'A'] = pii(1, 0); 
        dirs['S' - 'A'] = pii(-1, 0); 
        dirs['E' - 'A'] = pii(0, 1); 
        dirs['W' - 'A'] = pii(0, -1); 
        for (char c : path) {
            init.first += dirs[c - 'A'].first;
            init.second += dirs[c - 'A'].second; 
            if (p.find(init) != p.end()) {
                return true; 
            }
            p.insert(init); 
        }
        return false; 
    }
};
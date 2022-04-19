// https://leetcode.com/problems/the-skyline-problem


struct Elem {

    Elem(int x, int y, bool isStart): x(x), y(y), isStart(isStart) {}

    friend ostream& operator<<(ostream& os, const Elem& el); 

    int x;
    int y;
    bool isStart;
};

ostream& operator<<(ostream& os, const Elem& el) {
    os << "(" << to_string(el.x) << ", " << to_string(el.y) << ", " << (el.isStart?"S":"E") << ")"; 
    return os;
}


class Solution {
public:
    
    
    
    
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<Elem> bldgs; bldgs.reserve(buildings.size() * 2);
        for (auto v : buildings) {
            bldgs.push_back(Elem(v[0], v[2], true));
            bldgs.push_back(Elem(v[1], v[2], false));
        }
        
        sort(bldgs.begin(), bldgs.end(), [](const Elem& a, const Elem& b) -> bool {
            // return a.x < b.x || (a.x == b.x && a.y > b.y) || (a.x == b.x && a.y == b.y && a.isStart);    
            
            if (a.x < b.x) return true;
            if (a.x > b.x) return false;
            
            if (a.isStart && b.isStart) {
                return a.y > b.y; 
            } else if (!(a.isStart || b.isStart)) {
                return a.y < b.y;
            } else if (a.isStart && !b.isStart) {
                return true;
            } else {
                return false;
            }
        });
        
        // for (auto v : bldgs) cout << v << ' ';
        // cout << endl;
        
        map<int, int> ct;
        ct[0] = 1;
        vector<vector<int>> ans;
        for (auto b : bldgs) {
            if (b.isStart) {
                if (prev(ct.end()) -> first < b.y) {
                    ans.push_back({b.x, b.y});
                }
                ++ct[b.y];
            } else {
                if (prev(ct.end()) -> first == b.y && prev(ct.end()) -> second == 1) {
                    ans.push_back({b.x, prev(prev(ct.end())) -> first}); 
                }
                --ct[b.y];
                if (ct[b.y] == 0) {
                    ct.erase(b.y);
                }
            }
        }
        
        return ans;
    }
};



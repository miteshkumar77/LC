// https://leetcode.com/problems/self-crossing

class Solution {
public:
    struct PLine {
        PLine(int x1, int y1, int x2, int y2): x1(x1), y1(y1), x2(x2), y2(y2) {}
        PLine(): x1(0), y1(0), x2(0), y2(0){}
        int x1, y1, x2, y2;
    };
    
    void printPt(const PLine& pt) {
        printf("{(%d,%d),(%d,%d)}", pt.x1, pt.y1, pt.x2, pt.y2); 
    }
    
    bool intersects(const PLine& l1, const PLine& l2) {
        if ((l1.x1 == l1.x2 && l2.x1 == l2.x2) || (l1.y1 == l1.y2 && l2.y1 == l2.y2)) {
            return false;
        }
        
        int x_i;
        int y_i;
        
        if (l1.x1 == l1.x2) {
            if ((l2.y1 >= min(l1.y1, l1.y2) && l2.y1 <= max(l1.y1, l1.y2)) && 
                (l1.x1 >= min(l2.x1, l2.x2) && l1.x1 <= max(l2.x1, l2.x2))) {
                return true;
            } else {
                return false;
            }
        } else {
            return intersects(l2, l1); 
        }
    }
    bool isSelfCrossing(vector<int>& x) {
        vector<PLine> seen(8); 
        

        int num = 0;
        int curr = 0;
        array<int, 5> dirs{0, 1, 0, -1, 0};
        int dir = 0;
        PLine p;
        PLine lastPt;
        for (int i = 0; i < x.size(); ++i) {
            p.x1 = p.x2;
            p.y1 = p.y2;
            p.x2 += dirs[dir] * x[i];
            p.y2 += dirs[dir + 1] * x[i];
            dir = (dir + 1) % 4;
            for (int z = 0; z < num; ++z) {
                if (intersects(p, seen[z])) {
                    // printPt(p);
                    // cout << endl;
                    // printPt(seen[z]);
                    // cout << endl;
                    return true;
                }
            }
            
            if (i != 0) {
                seen[curr] = lastPt;
                curr = (curr + 1) % 8;
                num = min(8, num + 1); 
            }
            lastPt = p;
        }
        return false;
        
    }
};
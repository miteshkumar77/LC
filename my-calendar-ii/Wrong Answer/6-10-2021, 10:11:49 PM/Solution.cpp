// https://leetcode.com/problems/my-calendar-ii

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    vector<vector<int>> sb;
    vector<vector<int>> db;
    bool isOverlap(const vector<int>& a, const vector<int>& b) {
        return (a[0] <= b[0] && a[1] > b[0]) || (a[0] > b[0] && b[1] > a[0]);
    }
    
    vector<int> getOverlap(const vector<int>& a, const vector<int>& b) {
        return {max(a[0], b[0]), min(a[1], b[1])};
    }
    
    bool book(int start, int end) {
        vector<int> a{start, end};
        for (const auto& b : db) {
            if (isOverlap(a, b)) return false;
        }
        
        bool isDouble = false;
        for (const auto& b : sb) {
            if (isOverlap(a, b)) {
                isDouble = true;
                db.push_back(getOverlap(a, b));
            }
        }
        if (!isDouble) sb.push_back(a);
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
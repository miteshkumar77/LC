// https://leetcode.com/problems/my-calendar-ii

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    vector<vector<int>> sb;
    vector<vector<int>> db;
    
    bool book(int start, int end) {
        for (const auto& b : db) {
            if ((start >= b[0] && start < b[1]) || (b[0] >= start && b[0] < end)) return false;
        }
        
        for (const auto& b : sb) {
            if ((start >= b[0] && start < b[1]) || (b[0] >= start && b[0] < end))
                db.push_back({max(start, b[0]), min(end, b[1])});
        }
        sb.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
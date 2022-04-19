// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    map<int,int> starts;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        auto it = starts.lower_bound(start);
        if (it != starts.end() && end > it->first) return false;
        if (it != starts.begin() && prev(it)->second > start) return false;
        starts[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
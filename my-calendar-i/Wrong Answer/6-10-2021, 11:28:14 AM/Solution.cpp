// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    
    set<int> times;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = times.lower_bound(start);
        if (it != times.end()) {
            if (start <= *it && end > *it) return false;
        }  
        times.insert(start);
        times.insert(end - 1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
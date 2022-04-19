// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    map<int,int> points;
    
    int book(int start, int end) {
        points[start] += 1;
        points[end] -= 1;
        int k = 0;
        int ans = 0;
        for (const auto& p : points) {
            k += p.second;
            ans = max(ans, k);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
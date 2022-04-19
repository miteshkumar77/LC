// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if (q.empty() || q.back().first != t) {
            q.push_back(make_pair(t, 0));
        }
        ++count;
        q.back().second += 1;
        while(!q.empty() && q.front().first < t - 3000) {
            count -= q.front().second;
            q.pop_front();
        }
        return count;
    }
    
private:
    
    int count = 0;
    deque<pair<int,int>> q;
    int T = 3000;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
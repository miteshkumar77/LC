// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
public:
    RecentCounter() {
        n = 0;
    }
    
    int ping(int t) {
        while(!pings.empty() && pings.front().first < t - T) {
            n -= pings.front().second;
            pings.pop_front();
        }
        if (pings.empty() || pings.back().first != t) {
            pings.push_back(make_pair(t, 0));
        }
        pings.back().second++;
        ++n;
        return n;
    }
    
private:
    deque<pair<int,int>> pings;
    int n;
    int T = 3000;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
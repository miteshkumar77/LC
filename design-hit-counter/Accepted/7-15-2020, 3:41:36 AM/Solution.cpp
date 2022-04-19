// https://leetcode.com/problems/design-hit-counter

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ++hit_ct; 
        if (q.size() != 0 && q.front().first == timestamp) {
            ++(q.begin() -> second); 
        } else {
            q.push_front(make_pair(timestamp, 1)); 
        }
        while(q.size() != 0 && timestamp - 299 > q.back().first) {
            hit_ct -= q.back().second; 
            q.pop_back(); 
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(q.size() != 0 && timestamp - 299 > q.back().first) {
            hit_ct -= q.back().second; 
            q.pop_back(); 
        }
        return hit_ct; 
    }
private: 
    list<pair<int, int>> q; 
    int n = 300;
    int top_timestamp = 1; 
    int hit_ct = 0; 
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
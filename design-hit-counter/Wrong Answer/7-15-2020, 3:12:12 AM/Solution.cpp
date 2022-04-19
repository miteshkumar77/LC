// https://leetcode.com/problems/design-hit-counter

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        for (int i = 0; i < n; ++i) {
            q.push_back(0); 
        }
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (timestamp == top_timestamp) {
            (*q.begin())++; 
            hit_ct++; 
        } else {
            for (int i = top_timestamp; i < min(timestamp, top_timestamp + 301) - 1; ++i) {
                q.push_front(0); 
                hit_ct -= q.back(); 
                q.pop_back(); 
            }
            q.push_front(1); 
            hit_ct -= (q.back() - 1); 
            q.pop_back(); 
            top_timestamp = timestamp; 
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        for (int i = top_timestamp; i < min(timestamp, top_timestamp + 301); ++i) {
            q.push_front(0); 
            hit_ct -= q.back(); 
            q.pop_back(); 
        }
        return hit_ct; 
    }
private: 
    list<int> q; 
    int n = 301; 
    int top_timestamp = 1; 
    int hit_ct = 0; 
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
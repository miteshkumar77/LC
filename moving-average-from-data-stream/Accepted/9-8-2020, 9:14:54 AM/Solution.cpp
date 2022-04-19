// https://leetcode.com/problems/moving-average-from-data-stream

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = 0; 
        data = vector<int>(size); 
        head = 0; 
        tail = 0; 
    }
    
    double next(int val) {
        if (sz == data.size()) {
            head = (1 + head) % data.size(); 
            --sz;
        }
        ++sz; 
        data[tail] = val;
        tail = (1 + tail) % data.size(); 
        
        double ret = 0.0; 
        bool left = true; 
        for (int i = head; left || i != tail; i = (i + 1) % data.size()) {
            left = false; 
            ret += data[i]; 
        }
        ret /= sz; 
        return ret; 
    }
private:
    int sz; 
    vector<int> data;
    int head;
    int tail;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// https://leetcode.com/problems/moving-average-from-data-stream

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = 0; 
        data = vector<int>(size); 
        sum = 0; 
        head = 0; 
        tail = 0; 
    }
    
    double next(int val) {
        if (sz == data.size()) {
            sum -= data[head]; 
            head = (1 + head) % data.size(); 
            
            --sz;
        }
        ++sz; 
        sum += val;
        data[tail] = val;
        tail = (1 + tail) % data.size(); 
        
        return ((double)sum)/sz; 
    }
private:
    int sz; 
    vector<int> data;
    int head;
    int tail;
    int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
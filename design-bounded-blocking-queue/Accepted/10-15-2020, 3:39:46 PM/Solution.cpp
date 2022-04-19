// https://leetcode.com/problems/design-bounded-blocking-queue

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        this -> capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(lk);
        cv.wait(ul, [&] { return q.size() < capacity; });
        q.push(element);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(lk);
        cv.wait(ul, [&] { return q.size() > 0; });
        int ret = q.front(); q.pop();
        cv.notify_all();
        return ret;
    }
    
    int size() {
        return q.size();
    }
private:
    
    mutex lk;
    int capacity;
    condition_variable cv;
    queue<int> q;
};
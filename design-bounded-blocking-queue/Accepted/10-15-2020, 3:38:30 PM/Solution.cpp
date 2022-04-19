// https://leetcode.com/problems/design-bounded-blocking-queue

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        this -> capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(enqueue_lk);
        enqueue_cv.wait(ul, [&] { return q.size() < capacity; });
        q.push(element);
        enqueue_cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(enqueue_lk);
        enqueue_cv.wait(ul, [&] { return q.size() > 0; });
        int ret = q.front(); q.pop();
        enqueue_cv.notify_all();
        return ret;
    }
    
    int size() {
        return q.size();
    }
private:
    
    mutex enqueue_lk;
    mutex dequeue_lk;
    int capacity;
    condition_variable enqueue_cv;
    condition_variable dequeue_cv;
    queue<int> q;
};
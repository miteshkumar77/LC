// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    void balance() {
        while(abs((int)(left.size() - right.size())) > 1) {
            if (left.size() > right.size()) {
                right.push(left.top()); left.pop();
            } else {
                left.push(right.top()); right.pop();
            }
        }
        if (left.size() < right.size()) { left.push(right.top()); right.pop(); }
    }
    void addNum(int num) {
        right.push(num);
        balance();
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        } else {
            return ((double)left.top() + (double)right.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
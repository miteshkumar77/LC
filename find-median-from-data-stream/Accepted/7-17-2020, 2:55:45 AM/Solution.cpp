// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minq.push(num); 
        if (maxq.size() < minq.size() - 1) {
            maxq.push(minq.top());
            minq.pop(); 
        }
        
        if (maxq.size() != 0 && minq.size() != 0) {
            while(maxq.top() > minq.top()) {
                int maxqt = minq.top(); minq.pop(); 
                int minqt = maxq.top(); maxq.pop(); 
                maxq.push(maxqt);
                minq.push(minqt); 
            }
        }
    }
    
    double findMedian() {
        if (maxq.size() == minq.size()) {
            return ((double)(maxq.top() + minq.top()))/2; 
        } else {
            return minq.top(); 
        }
    }
    
    priority_queue<int, vector<int>, less<int>> maxq; 
    priority_queue<int, vector<int>, greater<int>> minq; 
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
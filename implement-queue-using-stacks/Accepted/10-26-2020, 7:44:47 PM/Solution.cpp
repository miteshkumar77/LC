// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        reverse();
        int ret = rstk.top();
        rstk.pop();
        reverse();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        reverse();
        int ret = rstk.top();
        reverse();
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
    
private:
    
    void reverse() {
        
        if (!stk.empty()) {
            while(!stk.empty()) {
                rstk.push(stk.top());
                stk.pop();
            }
        } else {
            while(!rstk.empty()) {
                stk.push(rstk.top());
                rstk.pop();
            }
        }
    }
    
    
    stack<int> stk;
    stack<int> rstk;
    
    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
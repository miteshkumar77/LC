// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
        stack<int> reg_s; 
        stack<int> min_stack; 
    MinStack() {
        reg_s = stack<int>(); 
        min_stack = stack<int>(); 
    }
    
    void push(int x) {
        reg_s.push(x);
        if (reg_s.size() == 1) {
            min_stack.push(x); 
        } else {
            min_stack.push(min(x, min_stack.top())); 
        }
    }
    
    void pop() {
        reg_s.pop(); 
        min_stack.pop(); 
    }
    
    int top() {
        return reg_s.top(); 
    }
    
    int getMin() {
        return min_stack.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
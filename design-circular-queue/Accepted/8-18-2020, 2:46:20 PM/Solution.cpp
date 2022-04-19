// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        buf = vector<int>(k);
        head = 0; 
        tail = 0; 
        flag_full = false; 
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (flag_full) {
            return false; 
        } else {
            buf[head++] = value; 
            head = head % buf.size(); 
            if (head == tail) {
                flag_full = true; 
            }
            return true; 
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!flag_full && tail == head) {
            return false; 
        }
        
        ++tail;
        tail = tail % buf.size();
        flag_full = false; 
        return true; 
        
    }
    
    /** Get the front item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1; 
        }
        if (head == 0) {
            return buf.back(); 
        } else {
            return buf[head - 1]; 
        }
    }
    
    /** Get the last item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1; 
        }
        return buf[tail]; 
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !flag_full && head == tail; 
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return flag_full; 
    }
    
private: 
    
    vector<int> buf;
    int head; 
    int tail; 
    bool flag_full; 
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
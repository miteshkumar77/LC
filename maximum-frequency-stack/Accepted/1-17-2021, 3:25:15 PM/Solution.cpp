// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        ++freq[x];
        lvl[freq[x]].push_back(x);
        if (freqval.empty() || freq[x] > freqval.top()) {
            freqval.push(freq[x]);
        }
    }
    
    int pop() {
        int ret = lvl[freqval.top()].back();
        lvl[freqval.top()].pop_back();
        --freq[ret];
        if (lvl[freqval.top()].size() == 0) {
            freqval.pop();
        }
        return ret;
    }
    
private:
    stack<int> freqval;
    unordered_map<int, vector<int>> lvl;
    unordered_map<int, int> freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
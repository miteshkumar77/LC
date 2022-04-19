// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage); 
    }
    
    void visit(string url) {
        ++current;
        latest = current;
        if (history.size() <= current) {
            history.push_back(url);
        } else {
            history[current] = url;
        }
    }
    
    string back(int steps) {
        current = max(0, current - steps); 
        return history[current];
    }
    
    string forward(int steps) {
        current = min(latest, current + steps); 
        return history[current];
    }
    int current = 0;
    int latest = 0;
    vector<string> history;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
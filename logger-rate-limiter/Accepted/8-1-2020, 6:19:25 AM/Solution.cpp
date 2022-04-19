// https://leetcode.com/problems/logger-rate-limiter

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        n = 10; 
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        // cout << n << endl; 
        
        while(!q.empty() && ((timestamp - n) >= q.front().first)) {
            for (string s : q.front().second) {
                seen.erase(s); 
            }
            q.pop(); 
        }
        bool ans = seen.find(message) == seen.end(); 
        
        if (ans) {
            if (!q.empty() && q.back().first == timestamp) {
                q.front().second.push_back(message);             
            } else {
                q.push(make_pair(timestamp, list<string>{message})); 
            }
            seen.insert(message); 
        }
        return ans; 
    }
private: 
    
    int n; 
    queue<pair<int, list<string>>> q; 
    unordered_set<string> seen; 
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
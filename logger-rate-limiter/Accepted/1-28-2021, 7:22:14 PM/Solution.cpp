// https://leetcode.com/problems/logger-rate-limiter

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (lim.count(message)) {
            if (timestamp - lim[message] >= n) {
                lim[message] = timestamp;
                return true;
            }
            return false;
        }
        lim[message] = timestamp;
        return true;
    }
    
private:
    
    unordered_map<string,int> lim;
    int n = 10;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
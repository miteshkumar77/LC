// https://leetcode.com/problems/sequentially-ordinal-rank-tracker

class SORTracker {
private:
    int i{0};
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> top;
    priority_queue<pair<int, string>, vector<pair<int, string>>, less<pair<int, string>>> bot;
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        pair<int, string> p{-1 * score, name};
        bool gte_top = (!top.empty() && (top.top() <= p));
        if (gte_top) {
            top.push(p);
        } else {
            bot.push(p);
        }
    }
    
    string get() {
        ++i;
        while(bot.size() < i) {
            bot.push(top.top());
            top.pop();
        }
        while(bot.size() > i) {
            top.push(bot.top());
            bot.pop();
        }
        return bot.top().second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
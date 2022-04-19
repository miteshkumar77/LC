// https://leetcode.com/problems/stream-of-characters

class StreamChecker {
    
    
private: 
    
    struct TN {
        array<TN*, 26> letters; 
        bool isEnd; 
        TN() {
            fill(letters.begin(), letters.end(), nullptr); 
            isEnd = false; 
        }
    };
    
    void insert(string& s, TN* head) {
        TN* cur = head; 
        for (char c : s) {
            if (!(cur -> letters)[c - 'a']) {
                (cur -> letters)[c - 'a'] = new TN(); 
            }
            cur = (cur -> letters)[c - 'a']; 
        }
        cur -> isEnd = true; 
    }
    
public:
    StreamChecker(vector<string>& words) {
        head = new TN();
        for (string w : words) {
            insert(w, head); 
        }
    }
    
    bool query(char letter) {
        q.push(head); 
        bool yes = false; 
        int sz = q.size(); 
        for (int i = 0; i < sz; ++i) {
            TN* t = q.front(); 
            q.pop(); 
            if ((t -> letters)[letter - 'a']) {
                t = (t -> letters)[letter - 'a']; 
                if (t -> isEnd) {
                    yes = true; 
                }
                q.push(t); 
            }
        }
        return yes; 
    }
    TN* head;  
    queue<TN*> q; 

};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
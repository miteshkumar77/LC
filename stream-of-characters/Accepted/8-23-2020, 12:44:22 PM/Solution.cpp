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
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i]; 
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
        TN* cur = head; 
        stream.push_front(letter); 
        for (char c : stream) {
            if ((cur -> letters)[c - 'a']) {
                cur = (cur -> letters)[c - 'a']; 
                if (cur -> isEnd) {
                    return true; 
                }
            } else {
                return false; 
            }
        }
        return false; 
    }
    TN* head;  
    list<char> stream; 

};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
class StreamChecker {
private:
    
    struct TN {
        array<TN*, 26> letters{};    
        bool is_end{false};
    };
    
    void insert(string const& s)
    {
        TN* cur = head;
        for (int i = (int)s.length() - 1; i >= 0; --i) {
            if (!(cur->letters)[s[i]-'a']) {
                (cur->letters)[s[i] - 'a'] = new TN();
            }
            cur = (cur->letters)[s[i] - 'a'];
        }
        cur->is_end = true;
    }
    
    
    TN* head;
    vector<char> stream;
    
public:
    StreamChecker(vector<string>& words) {
        head = new TN();
        for (string const& s : words) insert(s);
        stream.reserve(2000);
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        TN* cur = head;
        for (int i = (int)stream.size() - 1; i >= 0; --i) {
            cur = (cur->letters)[stream[i]-'a'];
            if (!cur) return false;
            if (cur->is_end) break;
        }
        return (cur != head && cur->is_end);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
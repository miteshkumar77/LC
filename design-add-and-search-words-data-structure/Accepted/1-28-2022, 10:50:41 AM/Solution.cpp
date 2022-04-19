// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
private:
    struct TN {
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
        }
        bool isEnd{false};
        array<TN*, 26> letters;    
    };
    
    TN* root;
public:
    WordDictionary() {
        root = new TN();
    }
    
    void addWord(string word) {
        TN* cur = root;
        for (char c : word) {
            if (!(cur->letters)[c-'a']) {
                (cur->letters)[c-'a'] = new TN();
            }
            cur = (cur->letters)[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        queue<pair<int,TN*>> q;
        q.push({0, root});
        while(!q.empty()) {
            auto [n, cur] = q.front(); q.pop();
            if (!cur) continue;
            if (n == (int)word.length()) {
                if (cur->isEnd) return true;
            } else {
                if (word[n] == '.') {
                    for (int i = 0; i < 26; ++i) {
                        q.push({n+1, (cur->letters)[i]});
                    }
                } else {
                    q.push({n+1, (cur->letters)[word[n]-'a']});
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
    
    
    
private: 
    
    
    struct TNode {
        array<TNode*, 26> letters; 
        bool isEnd; 
        
        TNode() {
            fill(letters.begin(), letters.end(), nullptr); 
            isEnd = false; 
        }
    };
    
    TNode* head; 
    
    
    
    bool search(int i, string& word, TNode* cur) {
        
        if (i >= word.length()) {
            return cur -> isEnd; 
        }
        if (word[i] == '.') {
            for (int x = 0; x < 26; ++x) {
                if ((cur -> letters)[x]) {
                    if (search(i + 1, word, (cur -> letters)[x])) {
                        return true; 
                    }
                }
            }
            return false; 
        }
        
        
        if (!(cur -> letters)[word[i] - 'a']) {
            return false; 
        } else {
            return search(i + 1, word, (cur -> letters)[word[i] - 'a']); 
        }
        
        
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new TNode(); 
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TNode* cur = head; 
        for (char c : word) {
            if (!(cur -> letters)[c - 'a']) {
                (cur -> letters)[c - 'a'] = new TNode(); 
            }
            cur = (cur -> letters)[c - 'a']; 
        }
        cur -> isEnd = true; 
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(0, word, head); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
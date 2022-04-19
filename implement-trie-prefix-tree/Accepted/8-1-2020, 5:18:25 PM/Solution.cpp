// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
    
private: 
    struct Node {
        array<Node*, 26> letters; 
        bool end; 
        
        Node() {
            fill(letters.begin(), letters.end(), nullptr); 
            end = false; 
        }
        
    }; 
    
    Node* head; 
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = head; 
        for (char c : word) {
            if (!(cur -> letters)[c - 'a']) {
                (cur -> letters)[c - 'a'] = new Node(); 
            }
            cur = (cur -> letters)[c - 'a']; 
        }
        cur -> end = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = head; 
        for (char c : word) {
            if (!(cur -> letters)[c - 'a']) {
                return false; 
            }
            cur = (cur -> letters)[c - 'a']; 
        }
        
        return cur -> end; 
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = head; 
        for (char c : prefix) {
            if (!(cur -> letters)[c - 'a']) {
                return false; 
            }
            cur = (cur -> letters)[c - 'a']; 
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
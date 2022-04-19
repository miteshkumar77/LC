// https://leetcode.com/problems/word-search-ii

class Solution {
    
    
private: 
    
    
    struct TN {
        array<TN*, 26> letters; 
        bool isEnd; 
        
        TN() {
            fill(letters.begin(), letters.end(), nullptr); 
            isEnd = false; 
        }
    }
    
    void insertWord(TN* head, string& word) {
        for (char c : word) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN(); 
            }
            head = (head -> letters)[c - 'a']; 
        }
        head -> isEnd = true; 
    }
    
    
    
    bool deleteWord(TN* head, string& word, int i) {
        if (i == word.length()) {
            bool isInt = false; 
            head -> isEnd = false; 
            for (int i = 0; i < 26; ++i) {
                if ((head -> letters)[i]) {
                    isInt = true;
                    break;
                }
            }
            
            if (!isInt) {
                delete head; 
                return true; 
            } else {
                return false; 
            }
            
        } else {
            bool res = deleteWord((head -> letters)[word[i] - 'a'], word, i + 1);
            if (!res) {
                return false; 
            } 
            
            (head -> letters)[word[i] - 'a'] = nullptr; 
            bool isInt = false;
            for (int i = 0; i < 26; ++i) {
                if ((head -> letters)[i]) {
                    isInt = true; 
                    break; 
                }
            }
            if (!isInt) {
                delete head; 
                return true; 
            } else {
                return false; 
            }
        }
    }
    
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false)); 
    }
    
    void bt(vector<string>& ans, string& s, TN* head, vector<vector<bool>>& visited, vector<vector<char>>& board, TN* actHead) {
        if (head -> isEnd) {
            if (deleteWord(actHead, ))
        }
    }
    
    
    
};
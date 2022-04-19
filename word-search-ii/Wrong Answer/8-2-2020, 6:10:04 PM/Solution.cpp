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
    };
    
    
    void insert(string& s, TN* head) {
        for (char c : s) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN(); 
            }
            head = (head -> letters)[c - 'a']; 
        }
        head -> isEnd = true; 
    }
    
    
    bool erase(string s, TN* head, TN*& inval, int i) {
        if (i == s.length()) {
            head -> isEnd = false; 
            bool isInt = false; 
            for (int i = 0; i < 26; ++i) {
                if ((head -> letters)[i]) {
                    isInt = true; 
                    break; 
                }
            }
            
            if (isInt) {
                return false; 
            } else {
                if (inval == head) {
                    inval = nullptr; 
                }
                delete head; 
                return true; 
            }
        } else {
            bool res = erase(s, (head -> letters)[s[i] - 'a'], inval, i + 1); 
            if (!res) {
                return false; 
            } else {
                (head -> letters)[s[i] - 'a'] = nullptr; 
                bool isInt = false; 
                for (int i = 0; i < 26; ++i) {
                    if ((head -> letters)[i]) {
                        isInt = true; 
                        break; 
                    }
                }
                if (isInt) {
                    return false; 
                } else {
                    if (inval == head) {
                        inval = nullptr; 
                    }
                    delete head; 
                    return true; 
                }
            }
        }
    }
    
    
    
public:
    
    
    
    
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TN* const head = new TN(); 
        for (string word : words) {
            insert(word, head); 
        }
        
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));         
        string box = ""; 
        vector<string> ans; 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        function<void(TN*,int,int)> bt = [&](TN* node, int i, int j) -> void {
            
            
            if (node -> isEnd) {
                ans.push_back(box); 
                // cout << box << endl; 
                // erase(box, head, node, 0); 
                node -> isEnd = false; 
                if (!node) {
                    // cout << "YE" << endl; 
                    return; 
                }
            }
            
            
            
            
            
            for (int x = 0; x < 4; ++x) {
                int n_i = dirs[x] + i; 
                int n_j = dirs[x + 1] + j; 
                if (n_i >= 0 && n_j >= 0 && n_i < board.size() && n_j < board[0].size() && !visited[n_i][n_j] && 
                   (node -> letters)[board[n_i][n_j] - 'a']) {
                    
                    visited[n_i][n_j] = true; 
                    box += board[n_i][n_j]; 
                    bt((node -> letters)[board[n_i][n_j] - 'a'], n_i, n_j); 
                    visited[n_i][n_j] = false; 
                    box.pop_back(); 
                    if (!node) {
                        return; 
                    }
                }
            }
        };
        
        
        for (int k = 0; k < board.size(); ++k) {
            for (int z = 0; z < board[k].size(); ++z) {
                if ((head -> letters)[board[k][z] - 'a']) {
                    box += board[k][z]; 
                    bt(head -> letters[board[k][z] - 'a'], k, z); 
                    box.pop_back(); 
                }
            }
        }
        return ans; 
    }
    
    
    
};
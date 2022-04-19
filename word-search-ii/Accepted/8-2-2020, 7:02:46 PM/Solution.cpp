// https://leetcode.com/problems/word-search-ii

class Solution {
    
    
private: 
    struct TN {
        array<TN*, 26> letters; 
        bool isEnd;
        bool explored; 
        TN() {
            fill(letters.begin(), letters.end(), nullptr); 
            isEnd = false; 
            explored = false; 
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
    
public:
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TN* const head = new TN(); 
        for (string word : words) {
            insert(word, head); 
        }
        int M = board.size(); 
        int N = board[0].size(); 
        
        vector<vector<bool>> visited(M, vector<bool>(N, false)); 
        string box = ""; 
        vector<string> ans; 
        array<int, 5> dirs{0, 1, 0, -1, 0}; 
        
        function<void(TN*,int,int)> bt = [&] (TN* cur, int i, int j) -> void {
            if (i >= 0 && j >= 0 && i < M && j < N && !visited[i][j] && (cur -> letters)[board[i][j] - 'a']) {
                visited[i][j] = true; 
                box += board[i][j]; 
                for (int x = 0; x < 4; ++x) {
                    bt((cur -> letters)[board[i][j] - 'a'], i + dirs[x], j + dirs[x + 1]); 
                }
                if ((cur -> letters[board[i][j] - 'a']) -> isEnd) {
                    (cur -> letters[board[i][j] - 'a']) -> isEnd = false; 
                    ans.push_back(box); 
                }
                box.pop_back(); 
                visited[i][j] = false; 
            } 
        };
        
        
        for (int k = 0; k < M; ++k) {
            for (int l = 0; l < N; ++l) {
                bt(head, k, l); 
            }
        }
        
        return ans; 
        
        
    }
    
    
    
};
// https://leetcode.com/problems/longest-word-in-dictionary

class Solution {
public:
    
    struct TN {
        
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
            isEnd = false;
        }
        
        bool isEnd;
        array<TN*, 26> letters;
    };
    
    void insert(TN* head, const string& word) {
        for (char c : word) {
            if (!(head->letters)[c - 'a']) {
                (head->letters)[c - 'a'] = new TN(); 
            }
            head = (head->letters)[c - 'a'];
        }
        head->isEnd = true;
    }
    
    string longestWord(vector<string>& words) {
        TN* head = new TN();
        head->isEnd = true;
        for (auto s : words) insert(head, s);
        
        string ans;
        string box;
        function<void(TN*)> dfs = [&](TN* root) -> void {
            
            for (int i = 0; i < 26; ++i) {
                if ((root->letters)[i] && (root->letters)[i]->isEnd) {
                    box.push_back('a' + i);
                    dfs((root->letters)[i]);
                    box.pop_back();
                }
            }
            if (ans.length() < box.length()) {
                ans = box;
            }
        };
        dfs(head);
        return ans;
    }
};
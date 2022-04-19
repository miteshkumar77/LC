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
    
    void dfs(TN* root, string& ans, string& box) {
        for (int i = 0; i < 26; ++i) {
            if((root->letters)[i] && (root->letters)[i]->isEnd) {
                box.push_back('a' + i);
                dfs((root->letters)[i], ans, box);
                box.pop_back();
            }
            (root->letters)[i] = nullptr;
        }
        if (ans.length() < box.length()) {
            ans = box;
        }
        delete root;
    }
    
    string longestWord(vector<string>& words) {
        TN* head = new TN();
        head->isEnd = true;
        for (auto s : words) insert(head, s);
        
        string ans;
        string box;
        
        dfs(head, ans, box);
        head = nullptr;
        return ans;
    }
};
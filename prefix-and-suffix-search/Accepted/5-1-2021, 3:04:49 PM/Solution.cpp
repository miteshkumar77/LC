// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter {
private:
    struct TN {
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
            id = -1;
        }
        array<TN*, 27> letters;
        int id;
    }; 
    
    void insert(TN* root, const string& wd, int id) {
        for (char c : wd) {
            if (!(root -> letters)[c - 'a']) {
                (root -> letters)[c - 'a'] = new TN();
            }
            root = (root -> letters[c - 'a']);
        }
        root -> id = id;
    }
    
    void dfs(TN* root, int& ans) {
        if (!root) return;
        ans = max(ans, root -> id);
        for (TN* c : root -> letters) dfs(c, ans);
    }
    
    int query(TN* root, const string& wd) {
        for (char c : wd) {
            root = (root -> letters)[c - 'a'];
            if (!root) {
                -1;
            }    
        }        
        int ret = -1;
        dfs(root, ret);
        return ret;
    }
public:
    TN* pref;
    
    WordFilter(vector<string>& words) {
        pref = new TN();
        int idx = 0;
        for (const string& s : words) {
            string tmp = "{" + s;
            int n = s.length();
            for (int i = n - 1; i >= 0; --i) {
                tmp = s[i] + tmp;
                insert(pref, tmp, idx);
            }
            ++idx;
        }
        
    }
    
    int f(string prefix, string suffix) {
        string qstr = suffix + "{" + prefix;
        return query(pref, qstr);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
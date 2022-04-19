// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter {
private:
    struct TN {
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
            id = -1;
        }
        array<TN*, 26> letters;
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
    
    void dfs(TN* root, vector<int>& ans) {
        if (!root) return;
        if (root -> id != -1) {
            ans.push_back(root -> id);
        }
        for (TN* c : root -> letters) dfs(c, ans);
    }
    
    vector<int> query(TN* root, const string& wd) {
        for (char c : wd) {
            root = (root -> letters)[c - 'a'];
            if (!root) {
                return vector<int>();
            }    
        }        
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
public:
    TN* pref;
    TN* suff;
    
    WordFilter(vector<string>& words) {
        pref = new TN();
        suff = new TN();
        int idx = 0;
        for (const string& s : words) {
            insert(pref, s, idx);
            ++idx;
        }   
        idx = 0;
        for (string s : words) {
            reverse(s.begin(), s.end());
            insert(suff, s, idx);
            ++idx;
        }
    }
    
    int f(string prefix, string suffix) {
        auto p = query(pref, prefix);
        auto s = query(suff, suffix);    
        sort(p.begin(), p.end());
        sort(s.begin(), s.end());
        int i = p.size(); --i;
        int j = s.size(); --j;
        while(i >= 0 && j >= 0) {
            if (p[i] > s[j]) {
                --i;
            } else if (p[i] < s[j]) {
                --j;
            } else {
                return p[i];
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
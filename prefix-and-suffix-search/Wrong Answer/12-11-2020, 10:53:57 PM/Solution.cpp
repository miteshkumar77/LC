// https://leetcode.com/problems/prefix-and-suffix-search

class WordFilter {
public:
    WordFilter(vector<string>& words) {
        fwHead = new TN();
        bwHead = new TN();
        this -> words = words;
        for (int i = 0; i < words.size(); ++i) {
            insert(i, fwHead);
            reverse(words[i].begin(), words[i].end());
            insert(i, bwHead);
        }
    }
    
    int f(string prefix, string suffix) {
        
        TN* fw = fwHead;
        TN* bw = bwHead;
        for (char c : prefix) {
            fw = (fw -> letters)[c - 'a']; 
            if (!fw) return -1;
        }
        
        for (char c : prefix) {
            bw = (bw -> letters)[c - 'a']; 
            if (!bw) return -1;
        }
        
        int j = (fw->ends).size() - 1; 
        int i = (bw->ends).size() - 1;
        
        while(j >= 0 && i >= 0) {
            if ((fw->ends)[j] > (bw->ends)[i]) {
                --i;
            } else if ((fw->ends)[j] > (bw->ends)[i]) {
                --j;
            } else {
                return i;
            }
        }
        return -1;
    }
private:
    
    struct TN {
        
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
        }
        array<TN*, 26> letters;
        vector<int> ends;
    };
    
    
    void insert(int i, TN* head) {
        string word = words[i];
        (head -> ends).push_back(i);
        for (char c : word) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN();
            }
            head = (head -> letters)[c - 'a']; 
            (head -> ends).push_back(i);
        }
    }
    
    
    
    
    TN* fwHead;
    TN* bwHead;
    vector<string> words; 
    
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
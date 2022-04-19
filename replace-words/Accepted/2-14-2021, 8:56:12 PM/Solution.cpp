// https://leetcode.com/problems/replace-words

class Solution {
    
    
    struct TN {
        
        TN() {
            fill(letters.begin(), letters.end(), nullptr);
            isEnd = false;
        }
        array<TN*, 26> letters;
        bool isEnd;
    };
    
    void insert(const string& wd, TN* head) {
        for (char c : wd) {
            if (!(head -> letters)[c - 'a']) {
                (head -> letters)[c - 'a'] = new TN();
            }
            head = (head -> letters)[c - 'a'];
        }
        head -> isEnd = true;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = sentence.length(); 
        TN* head = new TN(); 
        for (const string& wd : dictionary) {
            insert(wd, head); 
        }
        string ans;
        TN* curr = head;
        
        for (int i = 0; i < n; ++i) {
            ans.push_back(sentence[i]);
            if (sentence[i] == ' ') {
                curr = head;
                continue;
            }
            
            curr = (curr -> letters)[sentence[i] - 'a'];
            if (!curr) {
                curr = head;
                while(i + 1 < n && sentence[i] != ' ') {
                    ans.push_back(sentence[++i]);
                }
            } else if (curr -> isEnd) {
                curr = head; 
                while(i < n && sentence[i] != ' ') {
                    ++i;
                }
                
                if (i != n) ans.push_back(' ');
                
            }
        }
        return ans;
    }
};
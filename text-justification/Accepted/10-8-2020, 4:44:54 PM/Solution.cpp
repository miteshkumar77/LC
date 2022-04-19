// https://leetcode.com/problems/text-justification

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        
        function<string(int,int,int)> getLine = [&](int s, int e, int len) -> string {
            int spaces = maxWidth - len;
            int numWords = e - s + 1;
            if (numWords == 1) {
                return words[s] + string(spaces, ' ');
            }
            // cout << spaces << ' ' << numWords << endl;
            vector<int> spacesvec(numWords - 1, spaces/(numWords - 1));
            for (int i = 0; i < (spaces % (numWords - 1)); ++i) {
                ++spacesvec[i];
            }
            string ans;
            for (int i = 0; i < spacesvec.size(); ++i) {
                ans += words[s + i];
                ans += string(spacesvec[i], ' ');
            }
            ans += words[e];
            return ans;
        };
        
        // cout << getLine(0, 2, 8) << '|' << endl;
        // cout << getLine(3, 5, 13) << '|' << endl;
        int prev = 0;
        int len = 0;
        
        vector<string> ans;
        
        for (int i = 0; i < words.size(); ++i) {
            int numWords = i - prev + 1;
            int tlen = len + numWords - 1 + words[i].length();
            if (tlen > maxWidth) {
                ans.push_back(getLine(prev, i - 1, len));
                prev = i;
                len = 0;
            } 
            
            len += words[i].length();
        }
        string last;
        for (int i = prev; i < words.size() - 1; ++i) {
            last += words[i];
            last += ' ';
        }
        last += words.back();
        while(last.length() < maxWidth) {
            last += ' ';
        }
        ans.push_back(last);
        // ans.push_back(getLine(prev, words.size() - 1, len));
        return ans;
    }
    
    
};
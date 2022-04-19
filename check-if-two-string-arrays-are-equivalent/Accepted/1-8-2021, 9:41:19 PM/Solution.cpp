// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        array<int, 2> w1{0,0};
        array<int, 2> w2{0,0};
        while(w1[0] < word1.size() && w2[0] < word2.size()) {
            // cout << w1[0] << ' ' << w1[1] << "     " << w2[0] << ' ' << w2[1] << endl;
            if (word1[w1[0]][w1[1]++] != word2[w2[0]][w2[1]++]) {
                return false;
            }
            
            if (w1[1] >= word1[w1[0]].size()) {
                ++w1[0];
                w1[1] = 0;
            }
            
            if (w2[1] >= word2[w2[0]].size()) {
                ++w2[0];
                w2[1] = 0;
            }
        }
        
        return w1[0] >= word1.size() && w2[0] >= word2.size();
    }
};
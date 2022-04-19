// https://leetcode.com/problems/guess-the-word

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    bool checkWd(int common, const string& wd, const string& ref) {
        int numcommon = 0;
        for (int i = 0; i < 6; ++i) {
            numcommon += wd[i] == ref[i];
            if (common == 0 && numcommon > 0) return false;
        }
        return numcommon >= common;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_map<string, bool> words;
        for (string s : wordlist) {
            words.insert({s, false});
        }
        for (int i = 0; i < 10; ++i) {
            for (auto& p : words) {
                if (!p.second) {
                    int common = master.guess(p.first);
                    
                    if (common == 6) {
                        cout << "GUESSES: " << i << endl;
                        return;
                    }
                    
                    p.second = true;
                    unordered_map<string, bool> nw;
                    for (const auto& pi : words) {
                        if (checkWd(common, pi.first, p.first)) {
                            nw.insert(pi);
                        }
                    }
                    words = nw;
                    break;
                }
            }
        }
    }
};
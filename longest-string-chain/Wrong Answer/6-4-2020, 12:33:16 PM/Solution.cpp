// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> hashmap; 
        for (string word : words) {
            hashmap.insert(make_pair(word, 1)); 
        }
        int ans = 1; 
        for (string word : words) {
            
            for (int i = 0; i < word.length(); ++i) {
                string tmp = word.substr(0, i) + word.substr(i + 1, word.length() - i); 
                auto iter = hashmap.find(tmp); 
                if (iter != hashmap.end() && iter -> second + 1 > hashmap[word]) {
                    hashmap[word] = iter -> second + 1; 
                    if (hashmap[word] > ans) {
                        ans = hashmap[word]; 
                    }
                }
            }
        }
        return ans; 
    }
    
    
};
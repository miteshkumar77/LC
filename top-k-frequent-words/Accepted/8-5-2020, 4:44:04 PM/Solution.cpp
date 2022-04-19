// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq; 
        for (auto word : words) {
            ++freq[word]; 
        }
        
        auto compare = [&](string& a, string& b) -> bool {

        
            if (freq[a] > freq[b]) {
                return true; 
            } else if (freq[a] == freq[b] && a < b) {
                return true; 
            } else {
                return false; 
            }
        }; 
        
        priority_queue<string, vector<string>, decltype(compare)> minq(compare); 
        for (auto[word, ct] : freq) {
            minq.push(word); 
            if (minq.size() > k) {
                minq.pop(); 
            }
        }
        
        vector<string> ans(k); 
        
        while(!minq.empty()) {
            --k; 
            ans[k] = minq.top(); 
            minq.pop(); 
        }
        return ans; 
    }
};
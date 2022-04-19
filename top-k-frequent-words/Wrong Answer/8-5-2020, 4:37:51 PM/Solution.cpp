// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq; 
        for (auto word : words) {
            ++freq[word]; 
        }
        
        auto compare = [&](string& a, string& b) -> bool {
            return freq[a] > freq[b]; 
        }; 
        
        priority_queue<string, vector<string>, decltype(compare)> minq(compare); 
        for (auto[word, ct] : freq) {
            minq.push(word); 
            if (minq.size() > k) {
                minq.pop(); 
            }
        }
        
        vector<string> ans; ans.reserve(k); 
        while(!minq.empty()) {
            ans.push_back(minq.top()); 
            minq.pop(); 
        }
        return ans; 
    }
};
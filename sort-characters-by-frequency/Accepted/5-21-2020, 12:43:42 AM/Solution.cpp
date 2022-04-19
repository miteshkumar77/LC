// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqs; 
        for (char c : s) {
            if (freqs.find(c) == freqs.end()) {
                freqs[c] = 1; 
            } else {
                ++freqs[c]; 
            }
        }
        
        priority_queue<pair<int, char> > heap_sort; 
        for (auto iter = freqs.begin(); iter != freqs.end(); ++iter) {
            heap_sort.push(pair<int, char>(iter -> second, iter -> first)); 
        }
        
        string res = ""; 
        while(!heap_sort.empty()) {
            pair<int, char> top = heap_sort.top(); 
            heap_sort.pop(); 
            res += string(top.first, top.second); 
        } 
        
        return res; 
    }
};
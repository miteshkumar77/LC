// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> umap;  
        for (string s : strs) {
            array<int, 26> a = array<int, 26>(); 
            for (char c : s) {
                ++a[c - 'a']; 
            }
            umap[a].push_back(s); 
        }
        
        vector<vector<string>> result; 
        for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
            result.push_back(iter -> second); 
        }
        
        return result; 
    }
};
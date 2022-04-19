// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end()); 
        int j = 0; 
        for (int i = citations.size() - 1; i >= 1; --i) {
            ++j; 
            if (j <= citations[i] && (citations.size() - j) > citations[i - 1]) {
                return j; 
            }
            
        }
        return 0; 
    }
};
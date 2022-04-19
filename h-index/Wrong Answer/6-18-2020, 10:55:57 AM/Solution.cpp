// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end()); 
        int N = citations.size(); 
        
        int j = citations.size(); 
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] > (N - j)) {
                return j; 
            }
            --j; 
        }
        return 0; 
    }
};
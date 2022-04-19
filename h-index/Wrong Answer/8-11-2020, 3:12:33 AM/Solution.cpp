// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end()); 
        int x = 1; 
        for (int i = citations.size() - 1; i >= 0; --i) {
            
            if (citations[i] <= x) {
                cout << citations[i] << ' ' << x << endl; 
                return citations[i]; 
            }
            ++x; 
        }
        return 0; 
    }
};
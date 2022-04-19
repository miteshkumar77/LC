// https://leetcode.com/problems/gray-code

class Solution {
public:
    vector<int> grayCode(int n) {
        list<int> base; 
        base.push_back(0); 
        unsigned int powr = 1; 
        for (int i = 1; i <= n; ++i) {
            list<int>::iterator stop = prev(base.end()); 
            list<int>::iterator insert_it = base.end(); 
            for (auto it = base.begin(); it != next(stop); ++it) {
                insert_it = base.insert(insert_it, powr | (*it));
            }
            if (i != n) {
                powr = powr << 1; 
            }
        }
        return vector<int>(base.begin(), base.end()); 
    
    }
    
    
    
    
};
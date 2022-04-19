// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles

class Solution {
public:
    
    
    
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &pair) const
        {
            std::size_t h1 = std::hash<T1>()(pair.first);
            std::size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    
    Solution(vector<vector<int>>& rects) {
        unordered_set<pair<int, int>, pair_hash> mp; 
        
        for (vector<int> rect : rects) {
            for (int x = rect[0]; x <= rect[2]; ++x) {
                for (int y = rect[1]; y <= rect[3]; ++y) {
                    mp.insert(make_pair(x, y)); 
                }
            }
        }
        
        allpts = vector<pair<int, int>>(mp.begin(), mp.end()); 
    }
    
    vector<int> pick() {
        auto p = allpts[rand() % allpts.size()]; 
        
        return vector<int>{p.first, p.second}; 
    }
    
private: 
    vector<pair<int, int>> allpts; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
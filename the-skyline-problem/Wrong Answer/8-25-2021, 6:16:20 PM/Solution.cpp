// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    struct Elem {
        Elem(long long pos, long long height, bool end) : pos(pos), height(height), end(end) {}
        long long pos;
        long long height;
        bool end;
        bool operator<(Elem const& o) {
            if (pos < o.pos) {
                return true;
            } else if (pos > o.pos) {
                return false;
            } else {
                if (end && o.end) {
                    return height < o.height;
                } else if (!(end || o.end)) {
                    return height > o.height;
                } else {
                    return !end;
                }
            }
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<long long ,int> ht_ct;
        ++ht_ct[0];    
        vector<Elem> skl;
        skl.reserve(buildings.size() * 2);
        for (auto& v : buildings) {
            skl.push_back(Elem(v[0], v[2], false));
            skl.push_back(Elem((long long)v[1]+1, v[2], true));
        }
        
        sort(skl.begin(), skl.end());
        vector<vector<int>> ans;
        for (auto& e : skl) {
            if (!e.end) {
                if (e.height > prev(ht_ct.end())->first) {
                    ans.push_back({(int)e.pos, (int)e.height});
                }
                ++ht_ct[e.height];
            } else {
                if (e.height == prev(ht_ct.end())->first && ht_ct[e.height] == 1) {
                    ans.push_back({(int)(e.pos-1), (int)prev(prev(ht_ct.end()))->first});    
                }
                if (--ht_ct[e.height] == 0) ht_ct.erase(e.height);
            }
        }
        return ans;
    }
};
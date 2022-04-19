// https://leetcode.com/problems/create-sorted-array-through-instructions

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int ans = 0;
        auto e = getWay(instructions);
        for (auto v : e) ans += min(v[1], v[2]);
        
        return ans;
    }
    
    vector<array<int, 3>> getWay(const vector<int>& instructions) {
        int n = instructions.size();
        vector<array<int, 3>> vctr(n);
        for (int i = 0; i < n; ++i) {
            vctr[i] = {instructions[i], 0, 0};
        }
        
        return mergeSort(vctr);
        
    }
    
    vector<array<int, 3>> mergeSort(vector<array<int, 3>> data) {
        if (data.size() == 1) {
            return data;
        }
        int mid = data.size()/2;
        auto l = mergeSort(vector<array<int, 3>>(data.begin(), data.begin() + mid));
        auto r = mergeSort(vector<array<int, 3>>(data.begin() + mid, data.end()));
        int i = 0;
        int j = 0;
        vector<array<int, 3>> ret; ret.reserve(l.size() + r.size());
        
        while(i < l.size() || j < r.size()) {
            if (j >= r.size() || (i < l.size() && l[i][0] < r[j][0])) {
                ret.push_back(l[i++]);
            } else {
                ret.push_back(r[j++]);
                ret.back()[2] += l.size() - i;
                ret.back()[1] += i;
            }
        }
        return ret;
    }
};
// https://leetcode.com/problems/create-sorted-array-through-instructions

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        function<bool(int,int)> increasing = [](int a, int b) -> bool {
            return a < b; 
        };
        
        function<bool(int,int)> decreasing = [](int a, int b) -> bool {
            return a > b;
        };
        
        auto vlt = getWay(instructions, increasing);
        cout << "sorted first" << endl;
        auto vgt = getWay(instructions, decreasing);
        cout << "sorted second" << endl;
        int ans = 0;
        vector<int> sorted(vlt.size(), 0);
        for (int i = 0; i < vlt.size(); ++i) {
            sorted[vlt[i][2]] = vlt[i][1];
        }
        for (int i = 0; i < vgt.size(); ++i) {
            ans += min(sorted[vgt[i][2]], vgt[i][1]);
        }
        return ans;
    }
    
    vector<array<int, 3>> getWay(const vector<int>& instructions, function<bool(int,int)> cmp) {
        int n = instructions.size();
        vector<array<int, 3>> vctr(n);
        for (int i = 0; i < n; ++i) {
            vctr[i] = {instructions[i], 0, i};
        }
        
        return mergeSort(vctr, cmp);
        
    }
    
    vector<array<int, 3>> mergeSort(vector<array<int, 3>> data, 
                                    const function<bool(int,int)>& cmp) {
        if (data.size() == 1) {
            return data;
        }
        int mid = data.size()/2;
        auto l = mergeSort(vector<array<int, 3>>(data.begin(), data.begin() + mid), cmp);
        auto r = mergeSort(vector<array<int, 3>>(data.begin() + mid, data.end()), cmp);
        int i = 0;
        int j = 0;
        vector<array<int, 3>> ret; ret.reserve(l.size() + r.size());
        
        while(i < l.size() || j < r.size()) {
            if (j >= r.size() || (i < l.size() && cmp(l[i][0], r[j][0]))) {
                ret.push_back(l[i++]);
            } else {
                ret.push_back(r[j++]);
                ret.back()[1] += i;
            }
        }
        return ret;
    }
};
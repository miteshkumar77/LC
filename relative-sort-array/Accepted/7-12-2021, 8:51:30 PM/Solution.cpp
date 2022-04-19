// https://leetcode.com/problems/relative-sort-array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> pos;
        for (int i = 0; i < arr2.size(); ++i) {
            pos[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) -> bool {
            if (pos.count(a) && pos.count(b)) {
                return pos[a] < pos[b];
            } else if (!(pos.count(a) || pos.count(b))) {
                return a < b;
            } else {
                return pos.count(a);
            }
        });
        return arr1;
    }
};
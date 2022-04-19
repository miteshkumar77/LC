// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ct;
        for (int i : arr) ++ct[i];
        vector<pair<int,int>> amt;
        amt.reserve(ct.size());
        for (auto const & p : ct) amt.push_back(p);
        int sum = arr.size();
        int h = sum/2;
        sort(amt.begin(), amt.end(), [](pair<int,int> const & a, pair<int,int> const & b) -> bool {
            return a.second > b.second;
        });
        int i = 0;
        while(sum > h) {
            sum -= amt[i++].second;
        }
        return i;
    }
};
// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int const & a, int const & b) -> bool {
            return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
        });
        sort(arr.begin(), arr.begin() + min((size_t)k, arr.size()));
        return vector<int>(arr.begin(), arr.begin() + min((size_t)k, arr.size()));
    }
};
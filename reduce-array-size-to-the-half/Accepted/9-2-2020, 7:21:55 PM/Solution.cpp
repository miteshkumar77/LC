// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ct; 
        for (int i : arr) ++ct[i]; 
        auto compare = [&](int a, int b) -> bool {
            return ct[a] < ct[b]; 
        }; 
        priority_queue<int, vector<int>, decltype(compare)> pq(compare); 
        for (auto p : ct) pq.push(p.first); 
        int sum = 0;
        int lim = arr.size()/2; 
        if (arr.size() % 2 == 0) {
            --lim; 
        }
        int ans = 0; 
        while(sum <= lim) {
            sum += ct[pq.top()]; 
            pq.pop(); 
            ++ans; 
        }
        return ans; 
    }
};
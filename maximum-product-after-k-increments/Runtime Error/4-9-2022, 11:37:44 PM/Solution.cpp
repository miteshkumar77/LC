// https://leetcode.com/problems/maximum-product-after-k-increments

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i : nums) pq.push(i);
        while(k) {
            int t = pq.top(); pq.pop();
            pq.push(t+1);
            --k;
        }
        int M = 1e9 + 7;
        int a = 1;
        while(!pq.empty()) {
            int t = pq.top(); pq.pop();
            a = (a * t) % M;
        }
        return a;
    }
};
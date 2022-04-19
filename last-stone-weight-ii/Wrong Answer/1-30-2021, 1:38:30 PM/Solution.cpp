// https://leetcode.com/problems/last-stone-weight-ii

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> maxq(stones.begin(), stones.end()); 
        while(maxq.size() > 1) {
            int t1 = maxq.top(); maxq.pop();
            int t2 = maxq.top(); maxq.pop(); 
            t1 = abs(t2 - t1); 
            if (t1 != 0) {
                maxq.push(t1); 
            }
        }
        if (maxq.empty()) return 0;
        return maxq.top(); 
    }
};
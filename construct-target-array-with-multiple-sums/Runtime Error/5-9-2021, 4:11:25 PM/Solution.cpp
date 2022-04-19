// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        int tmp;
        if (n == 1) {
            return target[0] == 1;
        }
        priority_queue<int, vector<int>, less<int>> pq(target.begin(), target.end());
        int s = accumulate(target.begin(), target.end(), 0);
        int x;
        while(pq.top() > 1) {
            int t = pq.top();
            pq.pop();
            tmp = t;
            x = max(1, (t - 1)/(s - t));
            t = t - x * (s - t);
            s = s + t - tmp;
            if (t < 1) return false;
            pq.push(t);
        }
        return true;
    }
};
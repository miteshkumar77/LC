// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    typedef signed long long int slli;
    bool isPossible(vector<int>& target) {
        slli n = target.size();
        
        slli tmp;
        if (n == 1) {
            return target[0] == 1;
        }
        priority_queue<slli, vector<slli>, less<slli>> pq(target.begin(), target.end());
        slli s = accumulate(target.begin(), target.end(), (slli)0);
        slli x;
        slli t;
        while(pq.top() > 1) {
            t = pq.top();
            pq.pop();
            tmp = t;
            x = max((slli)1, (t - 1)/(s - t));
            t = t - x * s + x * t;
            s = s + t - tmp;
            if (t < 1) return false;
            pq.push(t);
        }
        return true;
    }
};
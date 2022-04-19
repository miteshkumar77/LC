// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    typedef unsigned long long int ulli;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<array<ulli, 2>> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = {(ulli)speed[i], (ulli)efficiency[i]};
        }
        sort(p.begin(), p.end(), [](const array<ulli,2>& a, const array<ulli,2>& b) -> bool {
            return a[1] > b[1];
        });
        
        priority_queue<int, vector<int>, greater<int>> mx;
        ulli sum = 0;
        ulli ans = 0;

        for (const auto& v : p) {
            sum += v[0];
            ans = max(ans, sum * v[1]);
            mx.push(v[0]);
            if (mx.size() == k) {
                sum -= mx.top(); mx.pop();
            }
        }
        return ans;
        
    }
};
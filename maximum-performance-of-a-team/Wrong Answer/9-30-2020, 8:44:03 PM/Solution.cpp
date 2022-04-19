// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> paired;
        for (int i = 0; i < n; ++i) {
            paired.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(paired.begin(), paired.end());

        vector<int> dp(n + 1, 0);
        priority_queue<int, vector<int>, less<int>> pq; 
        
        int sum = 0; 
        for (int i = n - 1; i >= 0; --i) {
            if (k == 1) continue;
            if (pq.size() > k - 2) {
                if (pq.top() < paired[i].second) {
                    sum -= pq.top();
                    sum += paired[i].second;
                    pq.pop();
                    pq.push(paired[i].second);
                }                                
            } else {
                pq.push(paired[i].second);
                sum += paired[i].second;
            }
            dp[i] = sum;
        }
        
        
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, paired[i].first * (dp[i + 1] + paired[i].second));
        }
        
        return ans;
        
        
    }
};
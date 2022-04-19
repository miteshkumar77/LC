// https://leetcode.com/problems/smallest-rotation-with-highest-score

class Solution {
public:
    int score(const vector<int>& A, int k) {
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (A[(i+k)%n] <= i);
        }
        return ans;
    }
    int bestRotation(vector<int>& A) {
        /*
            A[i], k, n score = 1 : A[i] <= (i - k + n) % n
            
        */
        int n = A.size();
        vector<vector<int>> intervals;
        int minidx;
        int maxidx;
        for (int i = 0; i < n; ++i) {
            if (A[i] == n) continue;
            minidx = A[i];
            maxidx = n - 1;
            if (i < minidx) {
                intervals.push_back({i + 1, 1});
                intervals.push_back({i + 1 + maxidx - minidx, -1});
            } else {
                intervals.push_back({0, 1});
                intervals.push_back({i - minidx, -1});
                if (i != n - 1) { 
                    intervals.push_back({i + 1, 1});
                    intervals.push_back({n - 1, -1});
                }
            }
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int ans = 0;
        int laps = 0;
        int mlaps = INT_MIN;
        for (const auto& p : intervals) {
            if (p[1] == 1) {
                ++laps;
                if (laps > mlaps) {
                    mlaps = laps;
                    ans = p[0];
                }
            } else {
                --laps;
            }
        }
        return ans;
    }
};

// [0,0,0,5,5,5]
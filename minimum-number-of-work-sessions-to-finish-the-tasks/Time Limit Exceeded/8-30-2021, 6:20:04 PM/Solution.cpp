// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks

class Solution {
public:
    bool bt(vector<int>& S, int T, int i, vector<int>& tasks) {
        if (i == tasks.size()) return true;
        for (int x = 0; x < S.size(); ++x) {
            if (S[x] + tasks[i] <= T) {
                S[x] += tasks[i];
                if (bt(S, T, i+1, tasks)) return true;
                S[x] -= tasks[i];
            }
        }
        return false;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.begin(), tasks.end());    
        reverse(tasks.begin(), tasks.end());
        int l = 1; int r = tasks.size();
        int mid; int ans = r;
        while(l <= r) {
            mid = l;
            vector<int> S(mid, 0);
            if (bt(S, sessionTime, 0, tasks)) {
                return mid;
            }
            l = mid + 1;
        }
        return tasks.size();
    }
};
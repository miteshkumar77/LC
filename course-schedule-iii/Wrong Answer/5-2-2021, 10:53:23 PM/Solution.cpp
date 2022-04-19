// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int total_time = 0;
        int ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] - a[0] < b[1] - b[0];
        });
        
        for(const auto& v : courses) {
            if (total_time + v[0] <= v[1]) {
                total_time += v[0];
                ++ans;
                pq.push(v[0]);
            } else {
                pq.push(v[0]);
                total_time += v[0];
                total_time -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
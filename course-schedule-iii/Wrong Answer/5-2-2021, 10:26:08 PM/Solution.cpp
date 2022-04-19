// https://leetcode.com/problems/course-schedule-iii

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int ans = 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return a[1] - a[0] < b[1] - b[0];
        });
        for (const auto& v : courses) {
            cout << v[0] << ' ' << v[1] << ' ' << v[1] - v[0] << endl;
        }
        int starttime = -1;
        int endtime = 0;
        //std::cout << "start: " << starttime << ' ' << "end: " << endtime << ' ' << "ans: " << ans << endl;
        for (const auto& v : courses) {
            
            if (v[1] - v[0] >= endtime) {
                starttime = endtime;
                endtime = starttime + v[0];
                ++ans;
            } else if (starttime + v[0] <= v[1] && starttime + v[0] <= endtime) {
                endtime = starttime + v[0];
            }
            //std::cout << "start: " << starttime << ' ' << "end: " << endtime << ' ' << "ans: " << ans << endl;
        }
        return ans;
    }
};
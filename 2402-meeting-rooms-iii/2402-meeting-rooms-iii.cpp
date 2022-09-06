class Solution {
public:
    using ll = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> open_rooms;
        for (int i = 0; i < n; ++i) open_rooms.push(i);
        vector<int> use_ct(n, 0);
        sort(meetings.begin(), meetings.end());
        /*
        cout << "[";
        for (int i = 0; i + 1 < meetings.size(); ++i) {
            cout << '[' << meetings[i][0] << ',' << meetings[i][1] << "],";
        }
        cout << '[' << meetings.back()[0] << ',' << meetings.back()[1] << "]]" << endl;
        */
        
        ll meeting{0};
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> arrivals;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> vacations;
        
        for (auto const& m : meetings) {
            arrivals.push({m[0], m[1] - m[0]});
        }
        ll t = 0;
        while(!arrivals.empty()) {
            while(!vacations.empty() && t >= vacations.top().first) {
                // cout << "t: " << t << " >> room " << vacations.top().second << " vacated" << endl;
                open_rooms.push(vacations.top().second);
                vacations.pop();
            }
            if (!open_rooms.empty()) {
                auto m = arrivals.top(); arrivals.pop();
                t = max(t, m.first);
                
            while(!vacations.empty() && t >= vacations.top().first) {
                // cout << "t: " << t << " >> room " << vacations.top().second << " vacated" << endl;
                open_rooms.push(vacations.top().second);
                vacations.pop();
            }
                int rm = open_rooms.top(); open_rooms.pop();
                ++meeting;
                ++use_ct[rm];
                // cout << "t: " << t << " >> meeting " << meeting << " vacating room " << rm << " at " << t + m.second << endl;
                vacations.push({t + m.second, rm});
            } else {
                t = max(t, vacations.top().first);
            }
        }
        // for (int i : use_ct) cout << i << ' ';
        // cout << endl;
        return std::distance(use_ct.begin(), std::max_element(use_ct.begin(), use_ct.end()));
    }
};
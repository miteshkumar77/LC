// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        array<int, 26> focc{-1};
        array<int, 26> locc{-1};
        for (int i = 0; i < 26; ++i) {
            focc[i] = -1;
            locc[i] = -1; 
        }
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i]; 
            if (focc[c - 'a'] == -1) {
                focc[c - 'a'] = i;
            }
            
            locc[c - 'a'] = i; 
        }
        
        vector<vector<int> > intervals;
        for (int i = 0; i < 26; ++i) {
            // cout << (char)(i + 'a') << ": " << focc[i] << ' ' << locc[i] << endl; 
            if (focc[i] != -1 && locc[i] != -1) {
                intervals.push_back(vector<int>{focc[i], locc[i]}); 
            }
        }
        // cout << intervals.size() << endl; 
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) -> bool {
           return a[1] < b[1]; 
        });
        
        vector<vector<int>> ansIntervals;
        ansIntervals.push_back(intervals.front());
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> currI = ansIntervals.back(); 
            if (currI[1] < intervals[i][0]) {
                ansIntervals.push_back(intervals[i]);
            } else {
                if (ansIntervals.back()[1] > intervals[i][1]) {
                    ansIntervals.back() = intervals[i]; 
                }
            }
        }
        
        vector<string> ans; 
        for (vector<int> i : ansIntervals) {
            ans.push_back(s.substr(i[0], i[1] - i[0] + 1));
        }
        return ans; 
    }
};
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
            if (focc[i] != -1 && locc[i] != -1) {
                intervals.push_back(vector<int>{focc[i], locc[i]});
            }
        }
        
        for (int i = 0; i < intervals.size(); ++i) {
            
            int mini = intervals[i][0]; 
            int maxi = intervals[i][1];
            for (int j = intervals[i][0]; j <= intervals[i][1]; ++j) {
                char c = s[j];
                mini = min(mini, focc[c - 'a']);
                maxi = max(maxi, locc[c - 'a']);
            }
            
            while(mini != intervals[i][0] || maxi != intervals[i][1]) {
                intervals[i][0] = mini;
                intervals[i][1] = maxi; 
                for (int j = intervals[i][0]; j <= intervals[i][1]; ++j) {
                    char c = s[j];
                    mini = min(mini, focc[c - 'a']);
                    maxi = max(maxi, locc[c - 'a']);
                }
            }
        }
        
        
        sort(intervals.begin(), intervals.end(), [] (vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0]; 
        });
        vector<vector<int> > ansi; 
        ansi.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> v = intervals[i]; 
            if (ansi.back()[1] < v[0]) {
                ansi.push_back(v);
            } else {
                if (ansi.back()[1] > v[1]) {
                    ansi.back() = v; 
                }
            }
        }
        
        
        vector<string> ans; 
        for (vector<int> v : ansi) {
            ans.push_back(s.substr(v[0], v[1] - v[0] + 1)); 
        }
        return ans; 
    }
};
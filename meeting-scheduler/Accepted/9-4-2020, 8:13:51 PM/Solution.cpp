// https://leetcode.com/problems/meeting-scheduler

class Solution {
public:
    typedef long long int lli; 
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
            return a[1] < b[1]; 
        };
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp); 
        int s1 = 0; 
        int s2 = 0; 
        while(s1 < slots1.size() && s2 < slots2.size()) {
            // cout << s1 << ' ' << s2 << endl; 
            lli min1 = slots1[s1][0]; lli max1 = slots1[s1][1]; 
            lli min2 = slots2[s2][0]; lli max2 = slots2[s2][1]; 

            
            
            lli overlap = min(max1, max2) - max(min1, min2); 
            if (overlap >= duration) {
                return vector<int>{(int)max(min1, min2), (int)(max(min1, min2) + (lli)duration)}; 
            }
            
            if (max2 <= max1) {
                ++s2; 
            } else {
                ++s1; 
            }
        }
        return vector<int>(); 
    }
};
// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        // vector<int> lis = ls(rating, true);
        // vector<int> lds = ls(rating, false);
        // for (int i : lis) cout << i << ' ';
        // cout << endl;
        // for (int j : lds) cout << j << ' ';
        // cout << endl;
        // int ans = 0;
        // int n = 0;
        // for (int i = 2; i < lis.size(); ++i) {
        //     if (lis[i] >= 3) {
        //         n = lis[i] - 1;
        //         ans += (n)*(n - 1)/2;
        //     }
        //     if (lds[i] >= 3) {
        //         n = lds[i] - 1;
        //         ans += (n)*(n - 1)/2;
        //     }
        // }
        // return ans;
        
        return ls(rating, true) + ls(rating, false);
    }
    
    int ls(const vector<int>& data, bool increasing) {
        int n = data.size();
        
        vector<int> ret(n, 0);
        int ans = 0;
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((data[i] > data[j] && increasing) || 
                    (!increasing && data[i] < data[j])) {
                    ans += ret[j];
                    ++ret[i];
                }
            }
        }
        return ans;
    }
};
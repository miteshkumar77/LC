// https://leetcode.com/problems/reach-a-number

class Solution {
public:
    int reachNumber(int target) {
        vector<vector<bool> > dp(abs(target) * 2 + 1, vector<bool>(abs(target) * 2 + 1, false));   
        dp[target][0] = true; 
        int target_idx = target * 2; 
        int L = target; 
        int R = target; 
        cout << target << endl; 
        for (int i = 1; i <= 2 * target - 1; ++i) {
            for (int j = L; j <= R; ++j) {
                if (dp[j][i - 1]) {
                    if (j - i >= 0) {
                        dp[j - i][i] = true; 
                        if (j - i == target_idx) {
                            for (int i = 0; i < dp[0].size(); ++i) {
                                for (int j = 0; j < dp.size(); ++j) {
                                    cout << dp[j][i] << ' '; 
                                }
                                cout << endl; 
                            }
                            return i; 
                        }
                    }

                    if (j + i < dp.size()) {
                        dp[j + i][i] = true; 
                        if (j + i == target_idx) {
                            for (int i = 0; i < dp[0].size(); ++i) {
                                for (int j = 0; j < dp.size(); ++j) {
                                    cout << dp[j][i] << ' '; 
                                }
                                cout << endl; 
                            }
                            return i; 
                        }
                    }
                }
            }
            
            L -= i; 
            R += i; 
        }
        
        
        for (int i = 0; i < dp[0].size(); ++i) {
            for (int j = 0; j < dp.size(); ++j) {
                cout << dp[j][i] << ' '; 
            }
            cout << endl; 
        }
        
        return -1; 
        
    }
};
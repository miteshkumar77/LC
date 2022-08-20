class Solution {
public:
    int find(vector<int> const& nums, int l, int r, int t) {
        int ans = -1;
        int mid;
        while(l <= r) {
            mid = l + (r - l)/2;
            if (nums[mid] >= t) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        auto t = set<int>(arr2.begin(), arr2.end());
        arr2 = vector<int>(t.begin(), t.end());
        /*
            dp[i][j][0]: minimum moves if leave arr1[i] as is
            dp[i][j][1]: minimum moves if arr1[i] = arr2[j];
        */
        int M = 1e9 + 7;
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(m, {M, M}));
        vector<array<int, 2>> pres(m);
        vector<array<int, 2>> pres2(m);
        int ans = M;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 1;
                } else {
                    if (arr1[i-1] < arr2[j]) {
                        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0] + 1);
                    }
                    if (arr1[i-1] < arr1[i]) {
                        dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0]);
                    }
                    int kp = find(arr2, 0, j-1, arr2[j]);
                    int k = find(arr2, 0, j, arr1[i]);
                    if (kp != -1) {
                        dp[i][j][1] = min(dp[i][j][1], pres2[kp][1] + 1);
                    }
                    if (k != -1) {
                        dp[i][j][0] = min(dp[i][j][0], pres2[k][1]);
                    }
                    /*
                    for (int k = 0; k <= j; ++k) {
                        
                        if (arr2[k] < arr2[j] && k < j) {
                            dp[i][j][1] = min(dp[i][j][1], dp[i-1][k][1] + 1);
                        }
                        if (arr2[k] < arr1[i]) {
                            dp[i][j][0] = min(dp[i][j][0], dp[i-1][k][1]);
                        }
                    }
                    */
                }
                if (j == 0) {
                    pres[j] = dp[i][j];
                } else {
                    pres[j][0] = min(dp[i][j][0], pres[j-1][0]);
                    pres[j][1] = min(dp[i][j][1], pres[j-1][1]);
                }
                if (i + 1 == n) {
                    ans = min(ans, min(dp[i][j][0], dp[i][j][1]));
                }
            }
            swap(pres, pres2);
        }
        return ans == M ? -1 : ans;
    }
};
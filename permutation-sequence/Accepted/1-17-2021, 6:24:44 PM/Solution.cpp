// https://leetcode.com/problems/permutation-sequence

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1); 
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) factorial[i] = i * factorial[i - 1];
        
        
        string s; 
        for (int i = 1; i <= n; ++i) {
            s.push_back(i + '0'); 
        }
        int num_left;
        
        
        for (int i = 0; i < n; ++i) {
            num_left = n - i - 1;
            for (int val = i + 1; val <= n; ++val) {
                if (val == n || factorial[num_left] * (val - i) >= k) {
                    swap(s[i], s[val-1]);
                    k -= factorial[num_left] * (val - i - 1); 
                    while(val - 1 > i + 1 && s[val - 1] < s[val - 2]) {
                        swap(s[val - 1], s[val - 2]);
                        --val;
                    }
                    break;
                }
            }
        }

        return s;
    }
};
// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = ""; 
        int maxtime = 0; 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                if (j != i) {
                    for (int k = 0; k < A.size(); ++k) {
                        if (k != i && k != j) {
                            for (int l = 0; l < A.size(); ++l) {
                                if (l != i && l != k && l != j) {
                                    if (getTime(vector<int>{A[i], A[j], A[k], A[l]}) >= maxtime) {
                                        ans = to_string(A[i]) + to_string(A[j]) + ":" + to_string(A[k]) + to_string(A[l]); 
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans; 
    }
    
    
    
    int getTime(vector<int> A) {
        int hr = A[0] * 10 + A[1]; 
        int min = A[2] * 10 + A[3]; 
        if (hr > 23 || min > 59) {
            return INT_MIN; 
        }
        return hr * 60 + min; 
    }
    
    
    
};
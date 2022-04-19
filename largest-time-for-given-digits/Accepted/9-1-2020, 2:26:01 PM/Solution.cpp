// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        string ans = ""; 
        int maxtime = -1; 
        do {
            int time = getTime(A); 
            if (time >= maxtime) {
                maxtime = time; 
                ans = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]); 
            }
        } while(next_permutation(A.begin(), A.end())); 
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
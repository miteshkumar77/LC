// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int initk = K; 
        function<bool(vector<int>&, vector<int>&)> lte = [&] (vector<int>& a, vector<int>& b) -> bool {
            unsigned long long int da = (long)a[0] * a[0] + (long)a[1] * a[1]; 
            unsigned long long int db = (long)b[0] * b[0] + (long)b[1] * b[1]; 
            return da <= db; 
        }; 
        
        int L = 0; int R = points.size() - 1; 
        
        while(L < R) {
            swap(points[rand() % (R - L + 1) + L], points[R]); 
            
            int i = L; 
            
            for (int j = L; j < R; ++j) {
                if (lte(points[j], points[R])) {
                    swap(points[j], points[i++]); 
                }
            }
            swap(points[i], points[R]); 
            
            if (i + 1 - L == K) {
                break; 
            } else if (i + 1 - L > K) {
                R = i - 1; 
            } else {
                L = i + 1; 
                K = K - i - 1 + L; 
            }
        }
        
        vector<vector<int>> ans; 
        for (int i = 0; i < initk; ++i) {
            ans.push_back(points[i]); 
        }
        return ans; 
    }
};
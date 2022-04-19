// https://leetcode.com/problems/image-overlap

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        set<pair<int,int>> pixels_A; 
        set<pair<int,int>> pixels_B; 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (A[i][j] == 1) {
                    pixels_A.insert(make_pair(i,j)); 
                }
                if (B[i][j] == 1) {
                    pixels_B.insert(make_pair(i,j)); 
                }
            }
        }
        
        function<int(int,int)> overlap = [&](int v, int h) -> int {
            int ans = 0; 
            for (auto p : pixels_A) {
                if (pixels_B.find(make_pair(p.first + v, p.second + h)) != pixels_B.end()) {
                    ++ans;
                }
            }
            return ans; 
        };
        int ans = 0; 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                ans = max(ans, overlap(i,j)); 
                ans = max(ans, overlap(-1*i, -1*j)); 
            }
        }
        return ans; 
    }
};
// https://leetcode.com/problems/image-overlap

class Solution {
    
private:
    struct pair_hash {
        inline std::size_t operator()(const std::pair<int,int> & v) const {
            return v.first*31+v.second;
        }
    };
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // unordered_set<pair<int,int>, pair_hash> pixels_A; 
        vector<pair<int,int>> pixels_A;
        unordered_set<pair<int,int>, pair_hash> pixels_B; 
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (A[i][j] == 1) {
                    pixels_A.push_back(make_pair(i,j)); 
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
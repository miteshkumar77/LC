class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end());
        int R = rectangles.size();
        vector<vector<int>> sums(R+1, vector<int>(102, 0));
        for (int i = R-1; i >= 0; --i) {
            for (int j = 100; j >= 0; --j) {
                sums[i][j] = sums[i+1][j] + (rectangles[i][1] >= j);
            }
        }
        int P = points.size();
        for (int i = 0; i < P; ++i)
            points[i].push_back(i);
        
        
        vector<int> ans(P);
        sort(points.begin(), points.end());
        int j = R-1;
        for (int i = P-1; i >= 0; --i) {
            while(j >= 0 && rectangles[j][0] >= points[i][0]) {
                --j;
            }
            ans[points[i][2]] = sums[j+1][points[i][1]];
        }
        return ans;
    }
};
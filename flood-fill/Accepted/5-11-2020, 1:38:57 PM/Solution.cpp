// https://leetcode.com/problems/flood-fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        array<array<int, 2>, 4> dirs = {array<int, 2>{0, 1}, array<int, 2>{1, 0}, array<int, 2>{0, -1}, array<int, 2>{-1, 0}}; 
        if (image[sr][sc] == newColor) {
            return image; 
        }
        
        queue<array<int, 2> > bfsq; 
        
        int start_image = image[sr][sc]; 
        image[sr][sc] = newColor; 
        bfsq.push(array<int, 2>{sr, sc}); 
        while(!bfsq.empty()) {
            array<int, 2> top = bfsq.front(); 
            bfsq.pop(); 
            for (array<int, 2> a : dirs) {
                array<int, 2> n = {top[0] + a[0], top[1] + a[1]}; 
                if (n[0] >= 0 && n[0] < image.size() && 
                    n[1] >= 0 && n[1] < image[0].size() && image[n[0]][n[1]] == start_image) {
                    image[n[0]][n[1]] = newColor; 
                    bfsq.push(n);
                    // cout << n[0] << ' ' << n[1] << "if" << endl; 
                } else {
                    // cout << n[0] << ' ' << n[1] << endl; 
                }
            }
        }
        
        return image; 
    }
};
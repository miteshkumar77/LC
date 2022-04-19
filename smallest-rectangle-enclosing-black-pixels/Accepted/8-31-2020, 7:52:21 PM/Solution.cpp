// https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // cout << x << ' ' << y << endl; 
        function<int(int,int,function<bool(int)>)> upper_bound = [](int L, int R, function<bool(int)> test) -> int {
            // cout << "UB: " << L << ' ' << R << endl; 
            int ans = L; 
            while(L <= R) {
                int mid = L + (R - L)/2; 
                if (test(mid)) {
                    ans = mid; 
                    L = mid + 1; 
                } else {
                    R = mid - 1; 
                }
            }
            return ans; 
        };
        
        function<int(int,int,function<bool(int)>)> lower_bound = [](int L, int R, function<bool(int)> test) -> int {
            // cout << "LB: " << L << ' ' << R << endl; 
            int ans = R; 
            while(L <= R) {
                int mid = L + (R - L)/2; 
                if (test(mid)) {
                    ans = mid; 
                    R = mid - 1; 
                } else {
                    L = mid + 1; 
                }
            }
            return ans; 
        };
        
        function<bool(int)> vertical_strip = [&](int j) -> bool {
            // cout << "j: " << j << endl; 
            for (int i = 0; i < image.size(); ++i) {
                if (image[i][j] == '1') {
                    return true; 
                }
            }
            return false; 
        };
        
        function<bool(int)> horizontal_strip = [&](int i) -> bool {
            // cout << "i: " << i << endl; 
            for (int j = 0; j < image[i].size(); ++j) {
                if (image[i][j] == '1') {
                    return true; 
                }
            }
            return false; 
        }; 
        
        int minx = lower_bound(0, y, vertical_strip);
        int maxx = upper_bound(y, image[0].size() - 1, vertical_strip); 
        int miny = lower_bound(0, x, horizontal_strip); 
        int maxy = upper_bound(x, image.size() - 1, horizontal_strip); 
        // cout << minx << ' ' << maxx << ' ' << miny << ' ' << maxy << endl; 
        return (maxx - minx + 1) * (maxy - miny + 1); 
        
    }
};
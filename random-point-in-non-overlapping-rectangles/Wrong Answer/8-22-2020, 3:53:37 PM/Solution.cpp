// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles

class Solution {
public:
    
    Solution(vector<vector<int>>& rects) {
        mrects.swap(rects); 
    
        csum = vector<int>(mrects.size()); 
        csum[0] = getArea(mrects[0]); 
        for (int i = 1; i < mrects.size(); ++i) {
            csum[i] = csum[i - 1] + getArea(mrects[i]); 
        }
        
        
    }
    
    vector<int> pick() {
        
        int L = 0; 
        int R = mrects.size() - 1; 
        
        int r = rand() % csum.back(); 
        int ans = -1; 
        while(L <= R) {
            int mid = L + (R - L)/2; 
            if (csum[mid] > r) {
                ans = mid; 
                R = mid - 1; 
            } else {
                L = mid + 1; 
            }
        }
        // if (ans != 0) {
        //     r -= csum[ans - 1]; 
        // }
        int rx = r % (mrects[ans][2] - mrects[ans][0]) + mrects[ans][0]; 
        int ry = r / (mrects[ans][2] - mrects[ans][0]) + mrects[ans][1]; 
        
        return vector<int>{rx, ry}; 
    }
    
private: 
    
    int getArea(const vector<int>& rect) {
        return (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1); 
    }
    
    vector<vector<int>> mrects; 
    vector<int> csum; 
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// https://leetcode.com/problems/count-number-of-teams

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        auto vec = getLT(rating);
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int num_left = i;
            int num_right = n - i - 1;
            int num_lt_left = vec[i][0];
            int num_lt_right = vec[i][1];
            int num_gt_left = num_left - num_lt_left;
            int num_gt_right = num_right - num_lt_right;
            ans += num_gt_left * num_lt_right + num_gt_right * num_lt_left;
        }
        return ans;
    }
    
    vector<array<int, 2>> getLT(const vector<int>& rating) {
        int n = rating.size();
        vector<array<int, 2>> vec; vec.reserve(n);    
        for (int i = 0; i < n; ++i) {
            vec.push_back({rating[i], i}); 
        }
        vector<array<int, 2>> copySpace(n);
        vector<array<int, 2>> numLT(n, {0, 0}); 
        mergeSort(vec, copySpace, 0, n - 1, numLT);
        
        return numLT;
        
    }
    
    void mergeSort(vector<array<int, 2>>& vec, vector<array<int, 2>>& copySpace, int l, int r, vector<array<int, 2>>& numLT) {
        if (l >= r) return;
        
        int mid = l + (r - l)/2;
        mergeSort(vec, copySpace, l, mid, numLT);
        mergeSort(vec, copySpace, mid + 1, r, numLT);
        
        for (int i = l; i <= r; ++i) {
            copySpace[i] = vec[i];
        }
        
        
        int lp = l;
        int le = mid + 1;
        int rp = mid + 1;
        int re = r + 1;
        int p = l;
        int l0 = lp;
        int r0 = rp;
        while(lp < le || rp < re) {
            if (rp >= re || (lp < le && copySpace[lp][0] < copySpace[rp][0])) {
                numLT[copySpace[lp][1]][1] += rp - r0;
                vec[p++] = copySpace[lp++];
            } else {
                numLT[copySpace[rp][1]][0] += lp - l0;
                vec[p++] = copySpace[rp++];
            }
        }
        
    }
    
    

};
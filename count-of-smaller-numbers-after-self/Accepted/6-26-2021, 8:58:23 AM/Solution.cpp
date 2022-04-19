// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    array<array<int,3>, 100000> swp;
    vector<array<int,3>> vec;
    void solve(int l, int r) {
        if (l >= r) {
            return;
        }
        
        int mid = l + (r - l)/2;
        solve(l, mid); solve(mid+1,r);
        int j = mid+1;
        for (int i = l; i <= mid; ++i) {
            while(j <= r && vec[j][0] < vec[i][0]) ++j;
            vec[i][1] += (j-mid-1);
        }
        int i = l;
        j = mid+1;
        for (int x = 0; x <= (r - l); ++x) {
            if (j > r || (i <= mid && vec[i][0] <= vec[j][0])) {
                swp[x] = vec[i++];    
            } else {
                swp[x] = vec[j++];
            }    
        }
        for (int i = l; i <= r; ++i) {
            vec[i] = swp[i-l];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vec = vector<array<int,3>> (n);
        for (int i = 0; i < n; ++i) {
            vec[i] = {nums[i], 0, i};
        }
        solve(0, n-1);
        for (const auto& v : vec) {
            nums[v[2]] = v[1];
        }
        return nums;
    }
};
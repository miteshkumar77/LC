// https://leetcode.com/problems/finding-pairs-with-a-certain-sum

class FindSumPairs {
public:
    map<int,int> n1;
    unordered_map<int, int> n2;
    vector<int>* nums1;
    vector<int>* nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i : nums1) ++n1[i];
        for (int i : nums2) ++n2[i];
        this->nums1 = &nums1;
        this->nums2 = &nums2;
    }
    
    void add(int index, int val) {
        int tmp = (*nums2)[index];
        (*nums2)[index] += val;
        --n2[tmp];
        if (n2[tmp] == 0) {
            n2.erase(tmp);
        }
        ++n2[tmp + val];
    }
    
    int count(int tot) {
        int ans = 0;
        for (const auto& p : n1) {
            if (p.first >= tot) break;
            ans += (p.second) * n2[tot - (p.first)];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
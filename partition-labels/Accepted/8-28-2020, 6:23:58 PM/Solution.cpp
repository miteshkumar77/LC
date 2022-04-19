// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        array<int, 26> st; fill(st.begin(), st.end(), INT_MAX); 
        array<int, 26> en; fill(en.begin(), en.end(), INT_MIN); 
        int i = 0; 
        for (char c : s) {
            st[c - 'a'] = min(st[c - 'a'], i); 
            en[c - 'a'] = max(en[c - 'a'], i); 
            ++i; 
        }
        
        vector<vector<int>> ints; 
        for (int i = 0; i < 26; ++i) {
            if (st[i] <= en[i]) {
                ints.push_back(vector<int>{st[i], en[i]}); 
                int nextmin = st[i]; int nextmax = en[i]; 
                while(true) {
                    for (int x = ints.back()[0]; x <= ints.back()[1]; ++x) {
                        nextmin = min(nextmin, st[s[x] - 'a']); 
                        nextmax = max(nextmax, st[s[x] - 'a']); 
                    }
                    if (nextmin < ints.back()[0] || nextmax > ints.back()[1]) {
                        ints.back()[0] = nextmin; 
                        ints.back()[1] = nextmax; 
                    } else {
                        break; 
                    }
                }
            }
            
           
        }
        
        sort(ints.begin(), ints.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0]; 
        }); 
        
        // for (auto i : ints) {
        //     cout << "[" << i[0] << ", " << i[1] << "], ";  
        // }cout << endl; 
        vector<vector<int>> merged; 
        merged.push_back(ints[0]); 
        
        for (int i = 1; i < ints.size(); ++i) {
            if (ints[i][0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], ints[i][1]); 
            } else {
                merged.push_back(ints[i]); 
            }
        }
        
        // for (auto i : merged) {
        //     cout << "[" << i[0] << ", " << i[1] << "], ";  
        // }cout << endl; 
        vector<int> ans; ans.reserve(merged.size()); 
        
        for (auto v : merged) {
            ans.push_back(v[1] - v[0] + 1); 
        }
        return ans; 
    }
};
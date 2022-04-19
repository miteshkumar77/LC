// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> fm; 
        for (int i : arr) {
            fm[i] += 1; 
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> mq; 
        for (pair<int, int> f : fm) {
            mq.push(make_pair(f.second, f.first)); 
        }
        
        for (int i = 0; i < k; ++i) {
            if (mq.size() == 0) {
                return 0; 
            }
            pair<int, int> t = mq.top(); 
            mq.pop(); 
            t.first--; 
            if (t.first != 0) {
                mq.push(t); 
            }
        }
        return mq.size(); 
    }
};
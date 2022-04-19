// https://leetcode.com/problems/flatten-nested-list-iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push(make_pair(&nestedList, 0)); 
    }
    
    
    void shuffle() {
        if (stk.empty()) {
            return; 
        } else if ((*stk.top().first).size() == stk.top().second) {
            stk.pop(); 
        } else if (!(*stk.top().first)[stk.top().second].isInteger()) {
            stk.push(make_pair(&((*stk.top().first)[stk.top().second++].getList()), 0)); 
        } else if ((*stk.top().first)[stk.top().second].isInteger()) {
            return; 
        }
        shuffle(); 
        
    }
    
    int next() {
        shuffle(); 
        int ans = (*stk.top().first)[stk.top().second++].getInteger();
        return ans; 
    }
    
    bool hasNext() {
        shuffle(); 
        return !stk.empty(); 
    }
    
    
private: 
    stack<pair<const vector<NestedInteger>*, int>> stk; 
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
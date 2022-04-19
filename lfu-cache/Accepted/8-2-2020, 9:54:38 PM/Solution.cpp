// https://leetcode.com/problems/lfu-cache

#include<bits/stdc++.h>

using namespace std; 


class LFUCache {
    
struct mapNode {
    int val; 
    list<pair<int, list<int>>>::iterator level_it; 
    list<int>::iterator sub_level_it; 
    
    mapNode() {
        
    }

    mapNode(int v) {
        val = v;
    }
};
    
    
    
    void printDeck() {
        for (auto it : lfreq) {
            cout << it.first << ": ";
            for (auto it2 : it.second) {
                cout << it2 << ' '; 
            }cout << endl; 
        }
    }
public:
    LFUCache(int capacity) {
        n = capacity; 
    }
    
    int get(int key) {
        if (n == 0) {
            return -1; 
        }
        // cout << "GET: " << key << endl; 
        auto it = lmap.find(key); 
        if (it == lmap.end()) {
            // cout << -1 << endl; 
            return -1; 
        }
        
        auto cur_lvl_it = (it -> second).second.level_it; 
        // cout << cur_lvl_it -> first << ' '; 
        auto cur_sub_lvl_it = (it -> second).second.sub_level_it; 
        // cout << (*cur_sub_lvl_it) << ' '; 
        (cur_lvl_it -> second).erase(cur_sub_lvl_it); 
        if (cur_lvl_it == lfreq.begin() || prev(cur_lvl_it) -> first > cur_lvl_it -> first + 1) {
            lfreq.insert(cur_lvl_it, make_pair(cur_lvl_it -> first + 1, list<int>{key})); 
        } else {
            (prev(cur_lvl_it) -> second).push_front(key); 
        }
        
        
        lmap[key].second.level_it = prev(cur_lvl_it); 
        lmap[key].second.sub_level_it = (prev(cur_lvl_it) -> second).begin(); 
        // cout << lmap[key].second.level_it -> first << ' '; 
        // cout << (*lmap[key].second.sub_level_it) << ' '; 

        if ((cur_lvl_it -> second).size() == 0) {
            lfreq.erase(cur_lvl_it); 
        }
        
        // printDeck(); 
        // cout << lmap[key].first << endl; 
        return lmap[key].first; 
        
        
    }
    
    void put(int key, int value) {
        // cout <<"PUT: " << key << ' ' << value << endl; 
        if (n == 0) {
            return; 
        }
        if (lmap.find(key) == lmap.end()) {
            if (lmap.size() >= n) {
            
                int del = lfreq.back().second.back(); 
                // cout << "DELETED: " << del << endl; 
                lfreq.back().second.pop_back(); 

                if (lfreq.back().second.size() == 0) {
                    lfreq.pop_back(); 
                }

                lmap.erase(del); 
            }
            
            if (lfreq.back().first != 1) {
                lfreq.push_back(make_pair(1, list<int>())); 
            }

            lfreq.back().second.push_front(key);
            
            mapNode tmp(key); 
            tmp.level_it = prev(lfreq.end());
            tmp.sub_level_it = lfreq.back().second.begin(); 
            lmap[key] = make_pair(value, tmp); 
        } else {
            lmap[key].first = value; 
            get(key); 
        }
        
        
        // printDeck(); 
    }
private:
    int n; 
    list<pair<int, list<int>>> lfreq; 
    unordered_map<int, pair<int, mapNode>> lmap; 
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ["LFUCache","put","put","get","put","get","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]
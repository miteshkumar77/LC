// https://leetcode.com/problems/flatten-2d-vector

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        outer_it = v.begin(); 
        inner_it = outer_it != v.end() ? outer_it->begin():inner_it; 
        end_it = v.end();
        push(); 
    }
    
    
    
    int next() {
        int ret = *inner_it;
        ++inner_it;
        push();
        return ret;
    }
    
    bool hasNext() {
        return outer_it != end_it;
    }
private:
    
    void push() {
        while(outer_it != end_it && inner_it == outer_it->end()) {
            ++outer_it;
            if (outer_it != end_it) {
                inner_it = outer_it->begin();
            }
        }
    }
    vector<vector<int>>::const_iterator end_it;
    vector<vector<int>>::const_iterator outer_it;
    vector<int>::const_iterator inner_it;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
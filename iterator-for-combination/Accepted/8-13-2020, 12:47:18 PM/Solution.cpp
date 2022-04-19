// https://leetcode.com/problems/iterator-for-combination

class CombinationIterator {
public:
    CombinationIterator(string tcharacters, int combinationLength) {
        stk.push(array<int, 2>{0, combinationLength}); 
        characters = tcharacters; 
        dub = ""; 
        longestlen = combinationLength; 
    }
    
    string next() {
        shuffle(); 
        stk.pop(); 
        return dub; 
    }
    
    bool hasNext() {
        shuffle(); 
        return !stk.empty(); 
    }
    
    
    void shuffle() {
        
        while(true) {
            if (stk.empty()) {
                return; 
            } else if (stk.top()[1] == 0) {
                return; 
            } else if (stk.top()[0] == characters.length() - stk.top()[1] + 1) {

                dub.pop_back();  
                stk.pop(); 
            } else {
                if (dub.length() != longestlen - stk.top()[1]) {
                    dub.pop_back(); 
                }
                dub += characters[stk.top()[0]]; 
                stk.push(array<int, 2>{++stk.top()[0], stk.top()[1] - 1}); 
            }
        }
    }
    
    int longestlen = 0; 
    string dub; 
    stack<array<int, 2>> stk; 
    string characters; 
    // {i, left}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
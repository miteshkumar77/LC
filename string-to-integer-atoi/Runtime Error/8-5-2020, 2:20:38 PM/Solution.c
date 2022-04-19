// https://leetcode.com/problems/string-to-integer-atoi



int myAtoi(char * str){
    int n = strlen(str); 
    int start_idx = 0; 
    while((*(str + start_idx)) == ' ') {
        ++start_idx; 
    }
    
    bool isNeg = false; 
    if ((*(str + start_idx)) == '-') {
        isNeg = true; 
        ++start_idx; 
    }
    
    else if ((*(str + start_idx)) == '+') {
        ++start_idx; 
    }
    
    int ans = 0; 
    int lastdig = INT_MAX % 10; 
    while(isdigit((*(str + start_idx)))) {
        if (ans / 10 > INT_MAX / 10 && ((*(str + start_idx) - '0') > lastdig)) {
            if (isNeg) {
                return INT_MIN; 
            } else {
                return INT_MAX; 
            }
        }
        
        ans = ans * 10 + ((*(str + start_idx)) - '0'); 
        ++start_idx; 
    }
    return (isNeg?-1:1) * ans; 
    
}
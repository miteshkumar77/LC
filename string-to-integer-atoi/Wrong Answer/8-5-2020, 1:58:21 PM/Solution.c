// https://leetcode.com/problems/string-to-integer-atoi



int myAtoi(char * str){
    size_t n = strlen(str); 
    if (n == 0) {
        return 0; 
    }
    bool neg = false; 
    bool found_num = false; 
    int start_idx = -1; 
    int end_idx = -1; 
    
    char intmax[] = "2147483647"; 
    char intmin[] = "2147483648";
    
    int ans = 0; 
    int acc = 1; 
    for (int i = 0; i < n; ++i) {
        
        if (found_num && !isdigit(*(str + i))) {
            break; 
        }
        if (((*(str + i)) == '-' || (*(str + i) == '+')) && (i + 1 < n) && isdigit(*(str + i + 1))) {
            neg = (*(str + i)) == '-'; 
            continue; 
        }
        
        if (isdigit(*(str + i))) {
            if (!found_num) {
                start_idx = i; 
            }
            end_idx = i; 
            found_num = true; 
        }
        
        if ((*(str + i)) == ' ' && !found_num) {
            continue; 
        }
        
        if (!isdigit(*(str + i)) && !found_num) {
            return 0; 
        }        
    }
    
   
    
    if(end_idx - start_idx + 1 > 10) {
        return neg?(-2147483648):(2147483647);  
    }
    
    if (end_idx - start_idx + 1 == 10) {
        int dig = 0; 

        for (int i = start_idx; i <= end_idx; ++i) {
            if (!neg) {
                if (intmax[dig] < str[i]) {
                    return 2147483647; 
                } else if (intmax[dig] > str[i]) {
                    break; 
                }
            } else {
                if (intmin[dig] < str[i]) {
                    return -2147483648; 
                } else if (intmin[dig] > str[i]) {
                    break; 
                }
            }
            ++dig; 
        }
    }
    
    
    for (int i = end_idx; i >= start_idx; --i) {
        
        if (neg) {
            ans -= (str[i] - '0') * acc; 
        } else {
            ans += (str[i] - '0') * acc; 
        }
        if (i != start_idx) {
            acc *= 10;
        }
    }
    
    
    return ans; 
    
    
}
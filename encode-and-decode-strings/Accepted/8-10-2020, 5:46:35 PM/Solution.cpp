// https://leetcode.com/problems/encode-and-decode-strings

class Codec {
public:
    
    
    
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string ans; 
        for (string s : strs) {
            ans += to_string(s.length()) + '|' + s; 
        }
        return ans; 
        
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans; 
        int i = 0; 
        while(true) {
            if (i >= s.length()) {
                break; 
            }
            
            string num = ""; 
            for (i; s[i] != '|'; ++i) {
                num += s[i]; 
            }
            
            int iters = stoi(num); 
            i += 1;
            
            string decode = ""; 
            for (int x = 0; x < iters; ++x, ++i) {
                decode += s[i]; 
            }
            ans.push_back(decode); 
        }
        return ans; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
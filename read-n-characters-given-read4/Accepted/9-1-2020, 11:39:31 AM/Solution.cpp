// https://leetcode.com/problems/read-n-characters-given-read4

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char* tmp = new char[4]; 
        int i = 0; 
        int numread; 
        do {
            numread = read4(tmp); 
            for (int x = 0; i + x < n && x < numread; ++x) {
                buf[i + x] = tmp[x]; 
            }
            i += numread; 
        } while(numread == 4 && i < n); 
        return min(n, i); 
    }
};
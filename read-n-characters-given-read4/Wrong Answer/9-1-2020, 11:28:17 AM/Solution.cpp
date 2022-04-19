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
        // buf = new char[n]; 
        int i = 0; 
        int numread = 0; 
        do {
            numread = read4(buf + i); 
            // for (int x = 0; x < i + numread; ++x) {
            //     cout << buf[x] << ' ';
            // }
            // cout << endl; 
            i += numread; 
        } while(numread == 4); 
        return i; 
    }
};
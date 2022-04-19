// https://leetcode.com/problems/integer-to-english-words

class Solution {
public:
    
    vector<string> ones {
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine"
    };
    
    vector<string> tens {
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
    };
    
    vector<string> twos {
        "ERROR",
        "ERROR",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"
    };
    
    vector<string> threes {
        "ERROR",
        "Thousand",
        "Million",
        "Billion"
    };
    
    string conv(string const& num) {
        if (num.length() == 0) return "";
        if (num[0] == '0') return conv(num.substr(1));
        if (num.length() > 3) {
            string suff = threes[(num.length()-1)/3];
            int part = num.length() % 3;
            part = part == 0 ? 3 : part;
            return conv(num.substr(0, part)) + " " + suff + " " + conv(num.substr(part));
        } else {
            if (num.length() == 3) {
                return ones[num[0] - '0'] + " Hundred " + conv(num.substr(1));
            } else if (num.length() == 2) {
                if (num[0] == '1') {
                    return tens[num[1] - '0'];
                } else {
                    return twos[num[0] - '0'] + " " + conv(num.substr(1));
                }
            } else {
                return ones[num[0] - '0'];
            }
        }
    }
    
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string s = to_string(num);
        string c = conv(s);
        int j = 0;
        int last = j;
        for (int i = 0; i < c.length(); ++i) {
            if (j == 0 || !(c[i] == ' ' && c[j-1] == ' ')) {
                c[j++] = c[i];
                if (c[i] != ' ') last = j;
            }
        }
        
        
        return c.substr(0, last);
    }
};
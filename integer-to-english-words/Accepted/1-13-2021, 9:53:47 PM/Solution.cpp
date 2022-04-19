// https://leetcode.com/problems/integer-to-english-words

class Solution {
public:
    
    string handleThree(string num) {
        while(num.length() > 0 && num[0] == '0') {
            num = num.substr(1, num.length() - 1);
        }
        
        if (num.length() == 1) {
            return ones[num[0] - '0'];
        } else if (num.length() == 2) {
            if (num[0] == '1') {
                return tens[num[1] - '0'];
            } else {
                string suff = handleThree(num.substr(1, num.length() - 1));
                return ys[num[0] - '0'] + (suff == ""?"":" " + suff); 
            }
        } else if (num.length() == 3) {
            string suff = handleThree(num.substr(1, num.length() - 1));
            return ones[num[0] - '0'] + " Hundred" + (suff == ""?"":" " + suff);
        } else {
            return "";
        }
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> groupThrees;
        string snum = to_string(num);
        int n = snum.length();
        string tmp;
        for (int i = n - 1; i >= 0; --i) {
            tmp = string(1, snum[i]) + tmp;
            if (tmp.length() == 3) {
                groupThrees.push_back(handleThree(tmp));
                tmp = "";
            }
        }
        if (tmp != "") {
            groupThrees.push_back(handleThree(tmp));
        }
        reverse(groupThrees.begin(), groupThrees.end());
        string ans = "";
        int place;
        for (int i = 0; i < groupThrees.size(); ++i) {
            if (groupThrees[i] != "") {
                ans += groupThrees[i] + " ";
                place = groupThrees.size() - i - 1;
                if (place != 0) {
                    ans += places[place] + " ";
                }
            }
        }        
        ans.pop_back();
        return ans;
    }
private:
    vector<string> ones {
            "",
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
        
        vector<string> ys {
            "",
            "",
            "Twenty",
            "Thirty",
            "Forty",
            "Fifty",
            "Sixty",
            "Seventy",
            "Eighty",
            "Ninety"
        };
        
        vector<string> places {
            "",
            "Thousand",
            "Million",
            "Billion"
        };
};
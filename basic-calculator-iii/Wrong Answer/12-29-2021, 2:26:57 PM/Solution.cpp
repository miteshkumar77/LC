// https://leetcode.com/problems/basic-calculator-iii

using namespace std;
class Solution {
public:
    enum Token_t { NUM, ADD, SUB, MUL, DIV, LP, RP };
    struct Token {
        Token(Token_t t): t(t), val(0) {}
        Token_t t;
        int   val;
    };


    vector<Token> tokens;
    int token_ptr{0};
    
    inline void print_tok(Token const& t) {
        switch(t.t) {
            case ADD:
                cout << "ADD";
                break;
            case SUB:
                cout << "SUB";
                break;
            case MUL:
                cout << "MUL";
                break;
            case DIV:
                cout << "DIV";
                break;
            case LP:
                cout << "LP";
                break;
            case RP:
                cout << "RP";
                break;
            case NUM:
                cout << "NUM(" << t.val << ")";
                break;
        }
    }

    void lex(string const& s) {
        for (char c : s) {
            if (isdigit(c)) {
                if (tokens.empty() || tokens.back().t != NUM) {
                    tokens.emplace_back(NUM);
                }
                tokens.back().val *= 10;
                tokens.back().val += (c-'0');
            } else if (c == ' ') {
                continue;
            } else if (c == '+') {
                tokens.emplace_back(ADD);
            } else if (c == '-') {
                tokens.emplace_back(SUB);
            } else if (c == '*') {
                tokens.emplace_back(MUL);
            } else if (c == '/') {
                tokens.emplace_back(DIV);
            } else if (c == '(') {
                tokens.emplace_back(LP);
            } else if (c == ')') {
                tokens.emplace_back(RP);
            }
        }
    }

    inline bool term(Token_t t, int& ans) {
        if (token_ptr >= tokens.size()) return false;
        ans = tokens.at(token_ptr).val;
        return tokens.at(token_ptr++).t == t;
    }

    inline bool term(Token_t t) {
        if (token_ptr >= tokens.size()) return false;
        return tokens.at(token_ptr++).t == t;
    }

    bool parse_Expr(int& ans) {
        int save = token_ptr;
        return parse_Expr1(ans)
            || (token_ptr = save, parse_Expr2(ans))
            || (token_ptr = save, parse_Expr3(ans));
    }

    bool parse_Expr1(int& ans) {
        int lans;
        int rans;
        if (parse_Expr_p(lans) && term(ADD) && parse_Expr(rans)) {
            ans = lans + rans;
            return true;
        }
        return false;
    }
    
    bool parse_Expr2(int& ans) {
        int lans;
        int rans;
        if (parse_Expr_p(lans) && term(SUB) && parse_Expr(rans)) {
            ans = lans - rans;
            return true;
        }
        return false;
    }

    bool parse_Expr3(int& ans) {
        return parse_Expr_p(ans);
    }

    bool parse_Expr_p(int& ans) {
        int save = token_ptr;
        return parse_Expr_p1(ans)
            || (token_ptr = save, parse_Expr_p2(ans))
            || (token_ptr = save, parse_Expr_p3(ans));
    }

    bool parse_Expr_p1(int& ans) {
        int lans;
        int rans;
        if (parse_Expr_p_p(lans) && term(MUL) && parse_Expr_p(rans)) {
            ans = lans * rans;
            return true;
        }
        return false;
    }

    bool parse_Expr_p2(int& ans) {
        int lans;
        int rans;
        if (parse_Expr_p_p(lans) && term(DIV) && parse_Expr_p(rans)) {
            ans = lans / rans;
            return true;
        }
        return false;
    }

    bool parse_Expr_p3(int& ans) {
        return parse_Expr_p_p(ans);
    }

    bool parse_Expr_p_p(int& ans) {
        int save = token_ptr;
        return parse_Expr_p_p1(ans)
            || (token_ptr = save, parse_Expr_p_p2(ans));
    }

    bool parse_Expr_p_p1(int& ans) {
        return term(NUM, ans);
    }

    bool parse_Expr_p_p2(int& ans) {
        return term(LP) && parse_Expr(ans) && term(RP);
    }

    
    int calculate(string s) {
        lex(s);
        int ans;
        parse_Expr(ans);
        return ans;
    }
};
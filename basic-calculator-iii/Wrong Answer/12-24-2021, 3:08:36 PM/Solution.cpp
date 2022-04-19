// https://leetcode.com/problems/basic-calculator-iii

class Solution {
public:
    enum Expr_t { Op, Term };
    enum Token_t { Add, Sub, Mul, Div, LPar, RPar, Val };
    struct Expr {
        Expr_t t;    
        
        // t == Op
        Expr* left;
        string op;
        Expr* right;
        
        // t ==  Term
        int val;
    };
    
    struct Token {
        Token(Token_t t, string val): t(t), val(val) {}
        Token_t t;
        string val;
    };
    
    Expr* make_Op(Expr* left, string op, Expr* right) {
        Expr* e = new Expr();
        e->t = Expr_t::Op;
        e->left = left;
        e->op = op;
        e->right = right;
        return e;
    }
    
    Expr* make_Term(int val) {
        Expr* e = new Expr();
        e->t = Expr_t::Term;
        e->val = val;
        return e;
    }
    
    vector<Token> lex(string const& s) {
        vector<Token> ret;
        for (char c : s) {
            switch (c) {
                case '+': ret.push_back(Token(Token_t::Add, "+")); break;
                case '-': ret.push_back(Token(Token_t::Sub, "-")); break;
                case '*': ret.push_back(Token(Token_t::Mul, "*")); break;
                case '/': ret.push_back(Token(Token_t::Div, "/")); break;
                case '(': ret.push_back(Token(Token_t::LPar, "(")); break;
                case ')': ret.push_back(Token(Token_t::RPar, ")")); break;
                default:
                    if (ret.size() == 0 || ret.back().t != Token_t::Val) {
                        ret.push_back(Token(Token_t::Val, ""));
                    }
                    ret.back().val.push_back(c);
                    break;
            }
        }
        return ret;
    }
    
    pair<Expr*, int> parse(vector<Token> & tokens, int i) {
        vector<Expr*> expr_stk;
        vector<Token> op_stk;
        for (; i < tokens.size(); ++i) {
            if (tokens[i].t == Token_t::Add ||
                tokens[i].t == Token_t::Sub ||
                tokens[i].t == Token_t::Mul ||
                tokens[i].t == Token_t::Div) {
                op_stk.push_back(tokens[i]);
            } else if (tokens[i].t == Token_t::LPar) {
                auto r = parse(tokens, i+1);
                i = r.second;
                expr_stk.push_back(r.first);
            } else if (tokens[i].t == Token_t::RPar) {
                break;
            } else if (tokens[i].t == Token_t::Val) {
                expr_stk.push_back(make_Term(stoi(tokens[i].val)));
                if (expr_stk.size() == 3) {
                    Expr* ret_expr;
                    if ((op_stk[0].t == Token_t::Add || op_stk[0].t == Token_t::Sub) &&
                        (op_stk[1].t == Token_t::Mul || op_stk[1].t == Token_t::Div)) {
                        ret_expr = make_Op(
                            expr_stk[0], op_stk[0].val, 
                            make_Op(expr_stk[1], op_stk[1].val, expr_stk[2]));
                    } else {
                        
                        ret_expr = make_Op(
                            make_Op(expr_stk[0], op_stk[0].val, expr_stk[1]), op_stk[1].val, expr_stk[2]);
                    }
                    expr_stk = vector<Expr*>{ret_expr};
                    op_stk = vector<Token>{};
                }
            }
        }
        if (expr_stk.size() == 2) {
            Expr* ret_expr = make_Op(expr_stk[0], op_stk[0].val, expr_stk[1]);
            expr_stk = vector<Expr*>{ret_expr};
        }
        return {expr_stk[0], i};
    }
    
    string print_tree(Expr* e) {
        if (e->t == Expr_t::Term) {
            return to_string(e->val);
        } else {
            return "("+print_tree(e->left)+e->op+print_tree(e->right) + ")";
        }
    }
    
    int eval(Expr* e) {
        if (e->t == Expr_t::Term) {
            return e->val;
        } else {
            auto l = eval(e->left);
            auto r = eval(e->right);
            if (e->op == "+") {
                return l+r;
            } else if (e->op == "-") {
                return l-r;
            } else if (e->op == "*") {
                return l*r;
            } else {
                return l/r;
            }
        }
    }
    int calculate(string s) {
        auto tokens = lex(s);
        
        Expr* e = parse(tokens, 0).first;
        // cout << print_tree(e) << endl;
        return eval(e);
    }
};
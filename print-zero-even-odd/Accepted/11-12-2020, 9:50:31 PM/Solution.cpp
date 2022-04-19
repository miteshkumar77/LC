// https://leetcode.com/problems/print-zero-even-odd

class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int i; 
    int var = 0; 
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        i = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lk(m); 
            // cout << "zero" << ' ' << var << endl;
            cv.wait(lk, [&] { return var == 0 || var == 2 || i > n; }); 
            if (i > n) {
                cv.notify_all(); 
                return;
            }
            var = (var + 1) % 4;
            printNumber(0);
            cv.notify_all(); 
        }
        
    }

    void even(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lk(m); 
            // cout << "even" << ' ' << var << endl;
            cv.wait(lk, [&] { return var == 3 || i > n; }); 
            if (i > n) {
                cv.notify_all(); 
                return;
            }
            var = (var + 1) % 4;
            printNumber(i++); 
            cv.notify_all(); 
        }
    }

    void odd(function<void(int)> printNumber) {
        while(true) {
            unique_lock<mutex> lk(m);
            // cout << "odd" << ' ' << var << endl;
            cv.wait(lk, [&] { return var == 1 || i > n; }); 
            if (i > n) {
                cv.notify_all(); 
                return;
            }
            var = (var + 1) % 4;
            printNumber(i++); 
            cv.notify_all(); 
        }
    }
};
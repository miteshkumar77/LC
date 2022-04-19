// https://leetcode.com/problems/print-in-order

class Foo {
public:
    Foo() {

    }
    
    
    
    
    void valve(int i, function<void()> action) {
        unique_lock<mutex> ul(m); 
        cv.wait(ul, [&] { return step == i; }); 
        ++step; 
        action(); 
        cv.notify_all(); 
    }

    void first(function<void()> printFirst) {
        valve(1, printFirst); 
        // printFirst() outputs "first". Do not change or remove this line.
    }

    void second(function<void()> printSecond) {
        valve(2, printSecond); 
        // printSecond() outputs "second". Do not change or remove this line.
    }

    void third(function<void()> printThird) {
        valve(3, printThird); 
        // printThird() outputs "third". Do not change or remove this line.
    }
private:
        condition_variable cv; 
        mutex m; 
        int step = 1; 
};
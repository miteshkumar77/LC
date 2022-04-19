// https://leetcode.com/problems/print-in-order

class Foo {
public:
    Foo() {

    }
    
    
    
    
    void valve(int i) {
        unique_lock<mutex> ul(m); 
        cv.wait(ul, [&] { return step == i; }); 
        ++step; 
        cv.notify_all(); 
    }

    void first(function<void()> printFirst) {
        valve(1); 
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        valve(2); 
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
    }

    void third(function<void()> printThird) {
        valve(3); 
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
        condition_variable cv; 
        mutex m; 
        int step = 1; 
};
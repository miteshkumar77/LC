class FooBar {
private:
    int n;
    condition_variable cv;
    mutex m;
    bool foo_{true};
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);       
            cv.wait(lk, [&]{ return foo_; });
        	// printFoo() outputs "foo". Do not change or remove this line.
            foo_ = false;
        	printFoo();
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [&]{ return !foo_; });
        	// printBar() outputs "bar". Do not change or remove this line.
            foo_ = true;
        	printBar();
            lk.unlock();
            cv.notify_one();
        }
    }
};
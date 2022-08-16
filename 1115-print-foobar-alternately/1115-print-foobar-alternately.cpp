class FooBar {
private:
    int n;
    condition_variable cv;
    mutex m;
    int j{0};
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);       
            cv.wait(lk, [&]{return j == 2 * i; });
        	// printFoo() outputs "foo". Do not change or remove this line.
            ++j;
        	printFoo();
            lk.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            cv.wait(lk, [&]{return j == (2 * i + 1); });
            ++j;
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            lk.unlock();
            cv.notify_one();
        }
    }
};
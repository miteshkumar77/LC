// https://leetcode.com/problems/the-dining-philosophers

class DiningPhilosophers {
public:
    mutex mtx;
    vector<bool> available;
    DiningPhilosophers() {
        available = vector<bool>(5, true);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        mtx.lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        mtx.unlock();
    }
};
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
        while(true) {
            mtx.lock();
            if (available[philosopher] && available[(philosopher + 1) % 5]) {
                available[philosopher] = false;
                available[(philosopher + 1) % 5] = false;
                pickLeftFork();
                pickRightFork();
                mtx.unlock();
                eat();
                putLeftFork();
                putRightFork();
                mtx.lock();
                available[philosopher] = true;
                available[(philosopher + 1) % 5] = true;
                mtx.unlock();
                return;
            }
            mtx.unlock();
        }
    }
};
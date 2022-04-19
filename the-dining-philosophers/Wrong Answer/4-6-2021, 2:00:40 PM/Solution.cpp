// https://leetcode.com/problems/the-dining-philosophers

class DiningPhilosophers {
public:
    array<mutex, 5> gmtx;
    mutex mtx;
    DiningPhilosophers() {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        mtx.lock();
        gmtx[philosopher].lock();
        pickLeftFork();
        gmtx[(philosopher + 1) % 5].lock();
        pickRightFork();
        mtx.unlock();
        eat();
        putLeftFork();
        gmtx[philosopher].unlock();
        putRightFork();
        gmtx[(philosopher + 1) % 5].unlock();
    }
};
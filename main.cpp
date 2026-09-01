#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex;
std::condition_variable condition;
int nextThread = 1;

void PrintThread(int number) {
    std::unique_lock<std::mutex> lock(mutex);

    
    condition.wait(lock, [number] { return nextThread == number; });

    std::cout << "thread " << number << '\n';

    ++nextThread;
    lock.unlock();
    condition.notify_all();
}

int main() {
    std::thread thread1(PrintThread, 1);
    std::thread thread2(PrintThread, 2);
    std::thread thread3(PrintThread, 3);

    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}

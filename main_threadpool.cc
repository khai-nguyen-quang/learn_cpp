#include "cpp_concurrency/thread_pool.hpp"
#include "cpp_concurrency/threadsafe_queue.hpp"

#include <string>
using namespace std;

void main_threadpool() {
    ThreadPool thread_pool{};
    ThreadSafeQueue<string> log_queue{};

    uint32_t max_tasks = thread::hardware_concurrency() * 10;

    // Reserve 1 task to print log message from other tasks
    atomic_bool stop(false);
    function<void()> task_print_log([&log_queue, &stop]{
        while(!stop) {
            string msg;
            if (log_queue.try_pop(msg)) {
                cout << msg << endl;
            }
        }
    });
    thread_pool.submit(task_print_log);

    for(uint32_t i=0; i < max_tasks; i++) {
        // create a task to do something
        function<void()> task([&log_queue, i]{
            string msg = "Task " + to_string(i) + " running...";
            log_queue.push(msg);
            this_thread::sleep_for(chrono::milliseconds(100));
        });
        // submit that task to thread_poll to be executed later
        thread_pool.submit(task);
    }

    // wait until all tasks are executed
    while(thread_pool.has_task()) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    stop = true;
    // Destructor of thread_pool ensures to wait all threads to be completed.
}
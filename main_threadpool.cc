#include "cpp_concurrency/thread_pool.hpp"
#include "cpp_concurrency/threadsafe_queue.hpp"

#include <string>
using namespace std;

void main_threadpool() {
    ThreadPool<int()> thread_pool{};
    ThreadSafeQueue<string> log_queue{};

    // futures to store returned value from tasks
    future<int> ret_print_task;
    vector<future<int>> ret_normal_tasks;

    uint32_t max_tasks = thread::hardware_concurrency() * 10;

    // Reserve 1 task to print log message from other tasks
    atomic_bool stop(false);
    function<int()> task_print_log([&log_queue, &stop] -> int{
        while(!stop) {
            string msg;
            if (log_queue.try_pop(msg)) {
                cout << msg << endl;
            }
        }
        return 0;
    });
    
    ret_print_task = thread_pool.submit(task_print_log);

    for(uint32_t i=0; i < max_tasks; i++) {
        // create a task to do something
        function<int()> task([&log_queue, i] -> int{
            string msg = "Task " + to_string(i) + " running...";
            log_queue.push(msg);
            this_thread::sleep_for(chrono::milliseconds(100));

            return 0;
        });
        // submit that task to thread_poll to be executed later
        future<int> f = thread_pool.submit(task);
        ret_normal_tasks.push_back(move(f));
    }

    // wait for all normal tasks to complete
    for (auto& f : ret_normal_tasks) {
        f.get();
    }

    // stop log print task
    stop = true;
    ret_print_task.get();

    // Destructor of thread_pool ensures to wait all threads to be completed.
}
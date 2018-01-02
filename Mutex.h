#pragma once
#include "Process.h"
#include <vector>

class Mutex {
private:
    std::vector<Process*> waiting_proceses;
    Process* using_process;
	bool is_lock;
public:
    Mutex();
    ~Mutex();

    void lock(Process& process);
    bool try_lock(Process& process);
    void unlock(Process& process);

    std::vector<Process*>& getWaitingProcess();
    Process& getUsingProcess();
    bool isBlock();
};
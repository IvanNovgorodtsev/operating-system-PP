#include "Mutex.h"

Mutex::Mutex() : using_process(), waiting_processes(), is_lock(false) {}

Mutex::~Mutex() {  }

void Mutex::lock(std::string &process) {
    if (proces_uzytkowy != nullptr && is_lock == true) {
		waiting_processes.push_back(&process);
	}
    else {
        using_process = &process;
		is_lock = true;
    }
}

bool Mutex::try_lock(std::string &process) {
    if (using_process == nullptr && is_lock == false) {
        using_process = &process;
		is_lock = true;
        return true;
    }
    return false;
}

void Mutex::unlock(Process &process) {
    if(using_process == &process && is_lock == true) {
        using_process = nullptr;
		is_lock = false;
        if(waiting_processes.size() != 0) {
            using_process = (waiting_processes[0]);
            waiting_processes.erase(waiting_processes.begin());
			is_lock = true;
        }
    }
}

Process & Mutex::getUsingProcess() {
    return &using_process;
}

std::vector<Process *> & Mutex::getWaitingProcesses() {
    return &waiting_processes;
}

bool Mutex::isBlock(){
    return !is_lock;
}
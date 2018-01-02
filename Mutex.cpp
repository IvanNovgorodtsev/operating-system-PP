#include "Mutex.h"

Mutex::Mutex() : using_process(), waiting_processes(), is_lock() {}

Mutex::~Mutex() {  }

void Mutex::lock(std::string &process) {
    if (proces_uzytkowy != nullptr) {
		waiting_processes.push_back(&process);
	}
    else {
        using_process = &process;
		is_lock = true;
    }
}

bool Mutex::try_lock(std::string &process) {
    if (using_process == nullptr) {
        using_process = &process;
		is_lock = true;
        return true;
    }
    return false;
}

void Mutex::unlock(Process &process) {
    if(using_process == &process) {
        using_process = nullptr;
		is_lock = false;
        if(waiting_processes.size() != 0) {
            using_process = (waiting_processes[0]);
            waiting_processes.erase(waiting_processes.begin());
			is_lock = true;
        }
    }
}

std::string & Mutex::getProcesUzytkowy() {
    return &using_process;
}

std::vector<std::string *> & Mutex::getProcesyOczekujace() {
    return &waiting_processes;
}

bool Mutex::isBlock(){
    return !is_lock;
}
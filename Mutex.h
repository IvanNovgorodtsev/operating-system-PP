#pragma once
#include "Process.h"
#include <vector>

class Mutex {
private:
	std::vector<PCB*> waiting_processes;
	PCB* using_process;
	bool is_lock;
public:
	Mutex();
	~Mutex();

	void lock(PCB& process);
	bool try_lock(PCB& process);
	void unlock(PCB& process);

	std::vector<PCB*>& getWaitingProcess();
	PCB& getUsingProcess();
	bool isBlock();

	std::string toString();
};
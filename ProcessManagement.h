#pragma once
#include<ostream>
#include<iostream>
#include<string>
#include<list>
#include"ID_Manager.h"
#include "PCB.h"
#include "Scheduler.h"

class ProcessManagement {
private:
	std::list<PCB> Processes;
	void addFirstProcess();
public:
	ID_Manager ID_Manager;
	ProcessManagement() {
		addFirstProcess();
	}
	void CreateProcess(std::string Name, std::string Path);
	void CreateEmptyProcess(std::string Name);

	void DeleteProcess(int ID);
	PCB::processState GetState(int ID);
	void SetState(int ID, PCB::processState newState);
	void print(int ID);
	int GetBasePriority(int ID);
	int GetCurrentPriority(int ID);
	void SetPriority(int ID, int Priority);
	int GetReg(int ID, char reg);
	void SetReg(int ID, char reg, int Value);
	int GetCommandCounter(int ID);
	void SetCommandCounter(int ID, int Val);
	std::string getNameFromId(int ID);
	int getIdFromName(std::string name);
	void Sleep(int ID);
	void WakeUp(int ID);
	PCB* getPCB(int ID);
};
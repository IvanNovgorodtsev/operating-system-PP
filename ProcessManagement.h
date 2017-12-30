#pragma once
#include<string>
#include<list>
#include"ID_Manager.h"

class PCB
{
public:
	enum class processState {newbie, waiting, ready, active, finished};
	std::string name;
	int ID;
	processState state;
	int priority;
	int basePriority;
	int commandCounter;
	int A;
	int B;
	int C;
	int D;

};


class ProcessManagement
{
private:
	std::list<PCB> Processes;
public:
	ID_Manager ID_Manager;

	void CreateProcess(std::string Name, std::string Path);
	//std::list<PCB>::iterator ProcessManagement::FindProcessIndex(int ID);
	void DeleteProcess(int ID);
	//int FindProcessIndex(int ID);
	//int GetState(int ID);
	PCB::processState ProcessManagement::GetState(int ID);
	void ProcessManagement::SetState(int ID, PCB::processState newState);
	int GetBasePriority(int ID);
	int GetCurrentPriority(int ID); 
	void SetPriority(int ID, int Priority);
	int GetReg(int ID, char reg);
	void SetReg(int ID, char reg, int Value);
	int GetCommandCounter(int ID); 
	void SetCommandCounter(int ID, int Val);
};
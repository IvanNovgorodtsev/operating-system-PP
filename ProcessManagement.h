#pragma once
#include<ostream>
#include<iostream>
#include<string>
#include<list>
#include"ID_Manager.h"

class PCB
{
public:
	enum processState {newbie, waiting, ready, active, finished};

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

	void print();
};


class ProcessManagement
{
private:
	std::list<PCB> Processes;
public:
	ID_Manager ID_Manager;

	void CreateProcess(std::string Name, std::string Path);
	void DeleteProcess(int ID);
	PCB::processState ProcessManagement::GetState(int ID);
	void ProcessManagement::SetState(int ID, PCB::processState newState);
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
};
#include "ProcessManagement.h"
#include<string>
#include<list>




void ProcessManagement::CreateProcess(std::string name, std::string Path)
{
	PCB temp;
	temp.state = PCB::processState::newbie;
	temp.name = name;
	temp.ID = ID_Manager.PickID();
	temp.A = 0;
	temp.B = 0;
	temp.C = 0;
	temp.D = 0;
	temp.commandCounter = 0;
	temp.state = PCB::processState::ready;
	Processes.push_back(temp);
}

void ProcessManagement::DeleteProcess(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{

		}
	}
}

PCB::processState ProcessManagement::GetState(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return 
		}
	}
}

void ProcessManagement::SetState(int ID, PCB::processState newState)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->state = newState;
		}
	}
}

int ProcessManagement::GetBasePriority(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return iter->basePriority;
		}
	}
}

int ProcessManagement::GetCurrentPriority(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return iter->priority;
		}
	}
}

void ProcessManagement::SetPriority(int ID, int Priority)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->priority = Priority;
		}
	}
}

int ProcessManagement::GetReg(int ID, char reg)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			switch (reg)
			{
			case 'A':
				return iter->A;
				break;

			case 'B':
				return iter->B;
				break;

			case 'C':
				return iter->C;
				break;
			case 'D':
				return iter->D;
				break;

			default:
				return -1;
				break;
			}
		}
	}
}

void ProcessManagement::SetReg(int ID, char reg, int Value)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			switch (reg)
			{
			case 'A':
				iter->A = Value;
				break;

			case 'B':
				iter->B = Value;
				break;

			case 'C':
				iter->C = Value;
				break;

			case 'D':
				iter->D = Value;
				break;

			default:
				break;
			}
		}
	}
}

int ProcessManagement::GetCommandCounter(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return iter->commandCounter;
		}
	}
}

void ProcessManagement::SetCommandCounter(int ID, int Val)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->commandCounter = Val;
		}
	}
}
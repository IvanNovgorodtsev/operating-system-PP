#include "ProcessManagement.h"
#include<string>
#include<list>


void PCB::print()
{
	std::cout << "Proces: " << name << ", identyfikator: " << ID << ", rejestry A: " << A << ", B: " << B << ", C: " << C << ", D: " << D << ", command counter: "<< commandCounter << std::endl;
}

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
	if (ID == 0)
	{
		std::cout << "Nie mozna usunac procesu bezczynnosci" << std::endl;
	}
	bool deleted = 0;
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			ID_Manager.ClearID(ID);
			Processes.erase(iter);
			deleted = 1;
			break;
		}
	}
	if (!deleted)
	{
		std::cout << "Proces o podanym ID nie istnieje" << std::endl;
	}

}

PCB::processState ProcessManagement::GetState(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return iter->state;
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

void ProcessManagement::print(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->print();
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
	return -1;
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
	return -1;
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
	return -1;
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

std::string ProcessManagement::getNameFromId(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			return iter->name;
		}
	}
		return "err";
}

int ProcessManagement::getIdFromName(std::string name)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->name == name)
		{
			return iter->ID;
		}
	}
	return -1;
}

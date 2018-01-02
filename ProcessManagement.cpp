#include "ProcessManagement.h"
#include<string>
#include<list>


//Wypisywanie zawartoúci pola PCB
void PCB::print()
{
	std::cout << "Proces: " << name << ", identyfikator: " << ID << ", rejestry A: " << A << ", B: " << B << ", C: " << C << ", D: " << D << ", command counter: "<< commandCounter << std::endl;
}
//Tworzenie nowego pola PCB
void ProcessManagement::CreateProcess(std::string Name, std::string Path)
{
	PCB temp;
	temp.state = PCB::processState::newbie;
	temp.name = Name;
	temp.ID = ID_Manager.PickID();
	temp.A = 0;
	temp.B = 0;
	temp.C = 0;
	temp.D = 0;
	temp.commandCounter = 0;
	temp.state = PCB::processState::ready;
	Processes.push_back(temp);
	//TRZEBA JAKOå DODAC KOD PROGRAMU DO RAMU
}
//Tworzenie pustego procesu 
void ProcessManagement::CreateEmptyProcess(std::string Name)
{
	PCB temp;
	temp.state = PCB::processState::newbie;
	temp.name = Name;
	temp.ID = ID_Manager.PickID();
	temp.A = 0;
	temp.B = 0;
	temp.C = 0;
	temp.D = 0;
	temp.commandCounter = 0;
	temp.state = PCB::processState::ready;
	Processes.push_back(temp);

}
//Tworzenie procesu bezczynnoúci
void ProcessManagement::addFirstProcess()
{
	CreateEmptyProcess("idle");
}
//Usuwanie wybranego procesu z listy procesÛw
void ProcessManagement::DeleteProcess(int ID)
{
	if (ID == 0)
	{
		std::cout << "Nie mozna usunac procesu bezczynnosci" << std::endl;
	}
	else
	{
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
}
//Pobieranie stanu wybranego procesu
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
//Nadawanie stanu procesu
void ProcessManagement::SetState(int ID, PCB::processState newState)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->state = newState;
			break;
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
			break;
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
	return -1;
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

void ProcessManagement::Sleep(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->state = PCB::processState::waiting;
			iter->blocked = 1;
			break;
		}
	}
}

void ProcessManagement::WakeUp(int ID)
{
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			iter->blocked = 0;
			break;
		}
	}
}
//Zwraca wskaünik do PCB
PCB * ProcessManagement::getPCB(int ID)
{
	PCB* temp = nullptr;
	for (std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter)
	{
		if (iter->ID == ID)
		{
			temp = &(*iter);
		}
	}
	return temp;
}

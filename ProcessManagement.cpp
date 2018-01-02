#include "ProcessManagement.h"
#include<string>
#include<list>


//Drukowanie zawartoœci pola PCB
void PCB::print() {
	std::cout << "Proces: " << name << ", identyfikator: " << ID << ", rejestry A: " << A << ", B: " << B << ", C: " << C << ", D: " << D << ", command counter: " << commandCounter << std::endl;
}
//Uspyianie procesu - pole blocked uniemo¿liwia ustawienie stanu ready
void PCB::sleep() {
	this->state = PCB::processState::waiting;
	this->blocked = 1;
}
//Budzenie procesu
void PCB::wakeup() {
	this->blocked = 0;
}

void PCB::setState(PCB::processState newState) {
	if(newState == PCB::processState::ready && this->blocked) {
		//nie mo¿na nadaæ stanu ready zablokowaneu procesowi
	}
	else {
		this->state = newState;
	}
}

//Tworzenie nowego pola PCB
void ProcessManagement::CreateProcess(std::string Name, std::string Path) {
	PCB temp;
	temp.state = PCB::processState::newbie;
	temp.name = Name;
	temp.ID = ID_Manager.PickID();
	temp.A = 0;
	temp.B = 0;
	temp.C = 0;
	temp.D = 0;
	temp.commandCounter = 0;
	temp.blocked = 0;
	temp.setState(PCB::processState::ready);
	//temp.state = PCB::processState::ready;
	Processes.push_back(temp);
	//TRZEBA JAKOŒ DODAC KOD PROGRAMU DO RAMU
}
//Tworzenie pustego procesu 
void ProcessManagement::CreateEmptyProcess(std::string Name) {
	PCB temp;
	temp.state = PCB::processState::newbie;
	temp.name = Name;
	temp.ID = ID_Manager.PickID();
	temp.A = 0;
	temp.B = 0;
	temp.C = 0;
	temp.D = 0;
	temp.commandCounter = 0;
	temp.setState(PCB::processState::ready);
	//temp.state = PCB::processState::ready;
	Processes.push_back(temp);

}
//Tworzenie procesu bezczynnoœci
void ProcessManagement::addFirstProcess() {
	CreateEmptyProcess("idle");
}
//Usuwanie wybranego procesu z listy procesów
void ProcessManagement::DeleteProcess(int ID) {
	if(ID == 0) {
		std::cout << "Nie mozna usunac procesu bezczynnosci" << std::endl;
	}
	else {
		bool deleted = 0;
		for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
			if(iter->ID == ID) {
				ID_Manager.ClearID(ID);
				Processes.erase(iter);
				deleted = 1;
				break;
			}
		}
		if(!deleted) {
			//B£¥D, BRAK PROCESU O PODANYM ID
			//std::cout << "Proces o podanym ID nie istnieje" << std::endl;
		}
	}
}
//Pobieranie stanu wybranego procesu
PCB::processState ProcessManagement::GetState(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			return iter->state;
		}
	}
}
//Nadawanie stanu procesu
void ProcessManagement::SetState(int ID, PCB::processState newState) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->setState(newState);
			break;
		}
	}
}
//Drukowanie zawartoœci PCB procesu o podanym ID
void ProcessManagement::print(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->print();
			break;
		}
	}
}
//Pobieranie priorytetu bazowego
int ProcessManagement::GetBasePriority(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			return iter->basePriority;
		}
	}
	return -1;
}
//Pobieranie aktualnego priorytetu
int ProcessManagement::GetCurrentPriority(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			return iter->priority;
		}
	}
	return -1;
}
//Nadawanie priorytetu
void ProcessManagement::SetPriority(int ID, int Priority) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->priority = Priority;
		}
	}
}
//Pobieranie zawartoœci rejestrów
int ProcessManagement::GetReg(int ID, char reg) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			switch(reg) {
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
//Nadawanie zawartoœci rejestrom
void ProcessManagement::SetReg(int ID, char reg, int Value) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			switch(reg) {
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
//Pobieranie wartoœci licznika komend
int ProcessManagement::GetCommandCounter(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			return iter->commandCounter;
		}
	}
	return -1;
}
//Ustawia wartoœæ licznika komend
void ProcessManagement::SetCommandCounter(int ID, int Val) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->commandCounter = Val;
		}
	}
}
//Zwraca nazwê na podstawie identyfikatora
std::string ProcessManagement::getNameFromId(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			return iter->name;
		}
	}
	return "err";
}
//Zwraca identyfikator procesu na podstawie nazwy
int ProcessManagement::getIdFromName(std::string name) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->name == name) {
			return iter->ID;
		}
	}
	return -1;
}
//Usypia proces
void ProcessManagement::Sleep(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->sleep();
			break;
		}
	}
}
//Budzi proces
void ProcessManagement::WakeUp(int ID) {
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			iter->wakeup();
			break;
		}
	}
}
//Zwraca wskaŸnik do PCB
PCB * ProcessManagement::getPCB(int ID) {
	PCB* temp = nullptr;
	for(std::list<PCB>::iterator iter = Processes.begin(); iter != Processes.end(); ++iter) {
		if(iter->ID == ID) {
			temp = &(*iter);
		}
	}
	return temp;
}

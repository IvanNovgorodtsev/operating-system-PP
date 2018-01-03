#include "PCB.h"

//Drukowanie zawarto�ci pola PCB
void PCB::print() {
	std::cout << "Proces: " << name << ", identyfikator: " << ID << ", rejestry A: " << A << ", B: " << B << ", C: " << C << ", D: " << D << ", command counter: " << commandCounter << std::endl;
}
//Uspyianie procesu - pole blocked uniemo�liwia ustawienie stanu ready
void PCB::sleep() {
	this->state = PCB::processState::waiting;
	this->blocked = 1;
}
//Budzenie procesu
void PCB::wakeup() {
	this->blocked = 0;
}

void PCB::setState(PCB::processState newState) {
	if (newState == PCB::processState::ready && this->blocked) {
		//nie mo�na nada� stanu ready zablokowaneu procesowi
	}
	else {
		this->state = newState;
	}
}
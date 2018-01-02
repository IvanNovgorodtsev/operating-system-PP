#pragma once
#include <array>
#include <queue>
#include <iostream>
#include <string>
#include "Process.h"

//BARDZO WAZNA RZECZ TRZEBA DODAC RECZNIE PROCES BEZCZYNNOSCI
class Scheduler {

protected:
	//Proces ktory aktualnie posiada procesor 
	Process runningProcess;
	//Znacznik mowiacy o potrzebie wywlaszczenia procesora 
	bool needResched;

	//Wektor kolejek procesow aktywnych	(przechowuje procesy aktywne)
	std::array <std::queue<Process>, 16> activeProcesses;
	//Wektor kolejek procesow przeterminowanych (przechowuje przeterminowane procesy)
	std::array <std::queue<Process>, 16> terminatedProcesses;

	//Wektor bitowy procesow aktywnych (ulatwiajacy i przyspieszajacy operacje na wektorach kolejek)
	std::array <bool, 16> bitsMapActive;
	//Wektor bitowy procesow przeterminowanch (ulatwiajacy i przyspieszajacy operacje na wektorach kolejek)
	std::array <bool, 16> bitsMapTerminated;

public:

	Scheduler();
	void addFirstProcess(PCB *process);
	void addProcess(PCB *process);
	void calculateCurrentPriority(Process &process);
	void translate(Process &process);
	void giveTime(Process &process);
	void deleteProcess(Process &process);
	void chooseProcess();
	void assignProcessor();
	void incWaitingTime();
	void terminated(Process &process);
	bool isTerminatedEmpty();
	void endOfEpoch();

	//METODY PRZEZNACZONE DO SHELLA
	void displayActiveProcesses();
	void displayTerminatedProcesses();
	void displayActiveBitsMap();
	void displayTerminatedBitsMap();
	void displayRunningProcess();

};
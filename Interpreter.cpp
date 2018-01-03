#include "Interpreter.h"
#include<conio.h>
#include<vector>
#define MAKSYMALNY_PRIORYTET 15
// TYMCZASOWE GLOBALNE ZMIENNE
int RejestrA=0, RejestrB=0, RejestrC=0, RejestrD=0;
int LicznikRozkazow=0;

//
Rozkazy convert(const string& operacja) // Funkcja dla konwersji rozkazow dla switcha
{
	if (operacja == "AD") return AD;
	else if (operacja == "AX") return AX;
	else if (operacja == "SB") return SB;
	else if (operacja == "MU") return MU;
	else if (operacja == "MX") return MX;
	else if (operacja == "MV") return MV;
	else if (operacja == "MZ") return MZ;
	else if (operacja == "MO") return MO;
	else if (operacja == "MY") return MY;
	else if (operacja == "JP") return JP;
	else if (operacja == "JZ") return JZ;
	else if (operacja == "CF") return CF;
	else if (operacja == "WF") return WF;
	else if (operacja == "DF") return DF;
	else if (operacja == "RF") return RF;
	else if (operacja == "CP") return CP;
	else if (operacja == "DP") return DP;
	else if (operacja == "RP") return RP;
	else if (operacja == "RM") return RM;
	else if (operacja == "SM") return SM;
	else if (operacja == "HL") return HL;
}
bool Interpreter::isLabel(string &program)
{
	if (program[program.size() - 1] == ':')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Interpreter::run(string &program/*Process RUNNING*/)
{
	int label=0;
	bool koniec = true;
	// PCBbox= RUNNING.getPCB(); // aktualny box procesu, mozemy wyciagnac nazwe, id itd
	// program = ram.pobierzRozkaz(RUNNING.GetName());
	if (!program.size())
	{
		cout << "Nie udalo sie pobrac rozkazu!" << endl;
	}
	if (isLabel(program))
	{
		label = LicznikRozkazow;
		LicznikRozkazow += program.size();
	}
	else
	{
		LicznikRozkazow += program.size();
		switch (convert(program.substr(0, 2)))
		{
		case AD:
		{
			if (program.substr(2, 1) == " ")
			{
				if (program.substr(3, 1) == "B")
				{
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')+processmanagement.GetReg(PCBbox.ID, 'B'));
					RejestrA += RejestrB;
				}
				else if (program.substr(3, 1) == "C")
				{
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')+processmanagement.GetReg(PCBbox.ID, 'C'));
					RejestrA += RejestrC;
				}
				else if (program.substr(3, 1) == "D")
				{
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')+processmanagement.GetReg(PCBbox.ID, 'D'));
					RejestrA += RejestrD;
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case AX:
		{
			// Obsluga bledu, czy rozkaz poprawny
			// dodac obsluge bledu, w przypadku gdy liczba przekracza wielkosc rejestru
			if (program.substr(2, 1) == " ")
			{
				int liczba = 0;
				liczba = atoi(program.substr(4, program.size() - 4).c_str());
				if (program.substr(3, 1) == "A")
				{
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')+liczba);
					RejestrA += liczba;
				}
				else if (program.substr(3, 1) == "B")
				{
					// processmanagement.SetReg(PCBbox.ID, 'B', processmanagement.GetReg(PCBbox.ID, 'B')+liczba);
					RejestrB += liczba;
				}
				else if (program.substr(3, 1) == "C")
				{
					// processmanagement.SetReg(PCBbox.ID, 'C', processmanagement.GetReg(PCBbox.ID, 'C')+liczba);
					RejestrC += liczba;
				}
				else if (program.substr(3, 1) == "D")
				{
					// processmanagement.SetReg(PCBbox.ID, 'D', processmanagement.GetReg(PCBbox.ID, 'D')+liczba);
					RejestrD += liczba;
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}

		case SB:
		{
			// Obsluga bledu, czy rozkaz poprawny
			// dodac obsluge bledu, w przypadku gdy liczba jest ujemna?
			if (program.substr(2, 1) == " ")
			{
				int liczba = 0;
				liczba = atoi(program.substr(4, program.size() - 4).c_str());
				if (program.substr(3, 1) == "A")
				{
					RejestrA -= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')-liczba);
				}
				else if (program.substr(3, 1) == "B")
				{
					RejestrB -= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'B', processmanagement.GetReg(PCBbox.ID, 'B')-liczba);
				}
				else if (program.substr(3, 1) == "C")
				{
					RejestrC -= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'C', processmanagement.GetReg(PCBbox.ID, 'C')-liczba);
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case MU:
		{
			if (program.substr(2, 1) == " ")
			{
				if (program.substr(3, 1) == "A")
				{
					RejestrA *= RejestrA;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')*processmanagement.GetReg(PCBbox.ID, 'A'));
				}
				else if (program.substr(3, 1) == "B")
				{
					RejestrA *= RejestrB;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')*processmanagement.GetReg(PCBbox.ID, 'B'));
				}
				else if (program.substr(3, 1) == "C")
				{
					RejestrA *= RejestrC;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')*processmanagement.GetReg(PCBbox.ID, 'C'));
				}
				else if (program.substr(3, 1) == "D")
				{
					RejestrA *= RejestrD;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')*processmanagement.GetReg(PCBbox.ID, 'C'));
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;

		}
		case MX:
		{
			if (program.substr(2, 1) == " ")
			{
				int liczba = 0;
				liczba = atoi(program.substr(4, program.size() - 4).c_str());
				if (program.substr(3, 1) == "A")
				{
					RejestrA *= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'A')*liczba);
				}
				else if (program.substr(3, 1) == "B")
				{
					RejestrB *= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'B', processmanagement.GetReg(PCBbox.ID, 'B')*liczba);
				}
				else if (program.substr(3, 1) == "C")
				{
					RejestrC *= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'C', processmanagement.GetReg(PCBbox.ID, 'C')*liczba);
				}
				else if (program.substr(3, 1) == "D")
				{
					RejestrD *= liczba;
					// processmanagement.SetReg(PCBbox.ID, 'D', processmanagement.GetReg(PCBbox.ID, 'D')*liczba);
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case MV:
		{
			if (program.substr(2, 1) == " ")
			{
				if (program.substr(3, 1) == "B")
				{
					RejestrA = RejestrB;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'B'));
				}
				else if (program.substr(3, 1) == "C")
				{
					RejestrA = RejestrC;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'C'));
				}
				else if (program.substr(3, 1) == "D")
				{
					RejestrA = RejestrC;
					// processmanagement.SetReg(PCBbox.ID, 'A', processmanagement.GetReg(PCBbox.ID, 'C'));
				}
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case JP:
		{	
			if (RejestrD != 0) // processmanagement.GetReg(PCBbox.ID, 'D') != 0
			{
				RejestrD--;
				//processmanagement.SetReg
				// liczba = atoi(program.substr(3, program.size() - 3).c_str());
				LicznikRozkazow = label;
			}
			break;
		}
		case CF:
		{
			if (program.substr(2, 1) == " ")
			{
				string name;
				name = program.substr(3, program.size() - 3).c_str();
				disc.tworzeniaPliku(name);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case WF:
		{
			if (program.substr(2, 1) == " ")
			{
				string name, data;
				name = program.substr(3, program.find(" ", 4) - 3).c_str(); // wyciagniecie nazwy z rozszerzeniem
				data = program.substr(program.find(" ", 3) + 1, program.size() - program.find(" ", 4)).c_str(); // wyciagniecie danych
				disc.wpisywanieDoPliku(name,data);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case DF:
		{
			if (program.substr(2, 1) == " ")
			{
				string name;
				name = program.substr(3, program.size() - 3).c_str();
				disc.usuwaniePliku(name);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case RF:
		{
			if (program.substr(2, 1) == " ")
			{
				string name, newname;
				name = program.substr(3, program.find(" ", 4) - 3).c_str(); // wyciagniecie nazwy z rozszerzeniem
				newname = program.substr(program.find(" ", 3) + 1, program.size() - program.find(" ", 4)).c_str(); // wyciagniecie danych
				disc.zmianaNazwy(name,newname);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case AF:
		{
			if (program.substr(2, 1) == " ")
			{
				string name, data;
				name = program.substr(3, program.find(" ", 4) - 3).c_str(); // wyciagniecie nazwy z rozszerzeniem
				data = program.substr(program.find(" ", 3) + 1, program.size() - program.find(" ", 4)).c_str(); // wyciagniecie danych
				disc.dopiszDoPliku(name,data);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
		}
		case CP:
		{
			if (program.substr(2, 1) == " ")
			{
				string name, path;
				name = program.substr(3, program.find(" ", 4) - 3).c_str(); // wyciagniecie nazwy
				path = program.substr(program.find(" ", 3) + 1, program.size() - program.find(" ", 4)).c_str(); // wyciagniecie sciezki																								// processmanagement.CreateProcess(name,path);
				// processmanagement.CreateProcess(name,path);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case DP:
		{
			if (program.substr(2, 1) == " ")
			{
				string name;
				int ID;
				name = program.substr(3, program.size() - 3).c_str();
				//ID=processmanagement.getIdFromName(name);
				// processesmanagment.DeleteProcess(ID);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case RP:
		{
			if (program.substr(2, 1) == " ")
			{
				string name;
				int ID;
				name = program.substr(3, program.size() - 3).c_str();
				// ID=Processes.getIdFromName(name); 
				// processesmanagment.setState(ID,1);
				// processesmanagment.SetPriority(ID, MAKSYMALNY_PRIORYTET + 1);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case RM:
		{
			if (program.substr(2, 1) == " ")
			{
				string name;
				name = program.substr(3, program.size() - 3).c_str();
				//komunikacja.read(name);
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case SM:
		{
			if (program.substr(2, 1) == " ")
			{
				string name, data;
				name = program.substr(3, program.find(" ", 4) - 3).c_str(); // wyciagniecie nazwy
				data = program.substr(program.find(" ", 3) + 1, program.size() - program.find(" ", 4)).c_str(); // wyciagniecie sciezki
				//komunikacja.write(name,data); 
			}
			else
			{
				cout << "Niepoprawny rozkaz" << endl;
			}
			break;
		}
		case HL:
		{
			koniec = false;
			break;
		}
		default:
		{
			cout << "Nie rozpoznano rozkazu." << endl;
			break;
		}
		}

		if (!koniec)
		{
			return 0;
		}
		else
		{
			return true;
		}
	}
}

Interpreter::Interpreter(/*RAM &ram, Dysk &dysk, ProcessManagement &processmanagement*/)
{
	// this->ram=ram;
	// this->dysk=dysk;
	// this
}

int main()
{
	// Dzialanie JP nie moze byc sprawdzone, bo licznik rozkazow 
	// nie zmienia rozkazu ktory jest wykonywany


	Interpreter interpreter;
	string program;
	program = "AX D 5";
	interpreter.run(program);
	program = "AX A 1";
	interpreter.run(program);
	while (RejestrD != 0)
	{
		program = "SILNIA:";
		interpreter.run(program);
		program = "MU D";
		interpreter.run(program);
		program = "JP";
		interpreter.run(program);
	}
	cout << RejestrA << endl;
}

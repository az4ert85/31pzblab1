#include "Notebook.h"
#include <iostream>
#include <string> 
#include <vector>


void Change(std::vector<Notebook>& records){
	std::string changer, changeTo;
	std::cout << "What do you whant change? (name, lastname, address, phone, mail)  ";
	std::getline(std::cin, changer);
	std::cout << "Change to ";
	std::getline(std::cin, changeTo);

	char param;
	int index = -1; std::vector<int> indexes;
	std::string str1, str2;
	std::cout << "Enter index(i) or data(d) for changing ";
	std::cin >> param; std::cin.ignore();
	if (param == 'i') {
		std::cout << "Enter index "; 
		std::cin >> index;
		std::cin.ignore();
	}
	else if (param == 'd') {
		std::cout << "Enter name: "; std::getline(std::cin, str1);
		std::cout << "\nEnter lastname: "; std::getline(std::cin, str2);
		int n = records.size();
		for (int i = 0; i < n; i++) {
			if (records[i].getName() == str1 && records[i].getLastname() == str2)
				if (index == -1) {
					index = i;
					indexes.push_back(i);
				}
				else indexes.push_back(i);
		}
		if (indexes.size() > 1) {
			std::cout << "Enter address: "; std::getline(std::cin, str1);
			n = indexes.size();
			for (int i = 0; i < n; i++) {
				if (records[indexes[i]].getAddress() == str1)
					index = i;
			}
		}
	}
	else std::cout << "\nInput incorect\n";

	records[index].ChangeNote(changer, changeTo);
	std::cout << "\n Note was changed: \n";
	records[index].WriteData();
}

void Search(std::vector<Notebook>& records) 
{
	int parametr;
	std::cout << "Choose parametr for search: 0 - note, 1 - name, 2 - lastname, 3 - address, 4 - phone\n";
	std::cin >> parametr; std::cin.ignore();

	std::string str_param;
	int count = 0;
	std::vector<int> indexes;

	switch (parametr) {
	case 0: {
		Notebook data;
		data.AddNote();
		std::cout << '\n';
		int index = SearchNote(data, records, records.size());
		if (index == -1)
			std::cout << "\nNote is not found\n";
		else {
			std::cout << '\n';
			records[index].WriteData();
			std::cout << '\n';
		}
	}break;

	case 1: {
		std::cout << "Enter name for search: ";
		std::getline(std::cin, str_param);
		std::cout << "Enter count of notes for search: ";
		std::cin >> count; std::cin.ignore();
		indexes = SearchName(str_param, records, records.size(), count);
		if (indexes.empty())
			std::cout << "\nNote is not found\n";
		else if (indexes.size() == 1) {
			std::cout << '\n';
			records[indexes[0]].WriteData();
		}
		else {
			int n = indexes.size();
			for (int i = 0; i < n; i++) {
				std::cout << '\n';
				records[indexes[i]].WriteData();
				std::cout << '\n';
			}
		}
	}break;

	case 2: {
		std::cout << "Enter lastname for search: ";
		std::getline(std::cin, str_param);
		std::cout << "Enter count of notes for search: ";
		std::cin >> count; std::cin.ignore();
		indexes = SearchLastname(str_param, records, records.size(), count);
		if (indexes.empty())
			std::cout << "\nNote is not found\n";
		else if (indexes.size() == 1) {
			std::cout << '\n';
			records[indexes[0]].WriteData();
			std::cout << '\n';
		}
		else {
			int n = indexes.size();
			for (int i = 0; i < n; i++) {
				std::cout << '\n';
				records[indexes[i]].WriteData();
				std::cout << '\n';
			}
		}
	}break;

	case 3: {
		std::cout << "Enter address for search: ";
		std::getline(std::cin, str_param);
		std::cout << "Enter count of notes for search: ";
		std::cin >> count; std::cin.ignore();
		indexes = SearchAddress(str_param, records, records.size(), count);
		if (indexes.empty())
			std::cout << "\nNote is not found\n";
		else if (indexes.size() == 1) {
			std::cout << '\n';
			records[indexes[0]].WriteData();
			std::cout << '\n';
		}
		else {
			int n = indexes.size();
			for (int i = 0; i < n; i++) {
				std::cout << '\n';
				records[indexes[i]].WriteData();
				std::cout << '\n';
			}
		}
	}break;

	case 4: {
		std::cout << "Enter phone for search: ";
		std::getline(std::cin, str_param);
		std::cout << "Enter count of notes for search: ";
		std::cin >> count; std::cin.ignore();
		int index = SearchPhone(str_param, records, records.size());
		if (index == -1)
			std::cout << "\nNote is not found\n";
		else {
			std::cout << '\n';
			records[index].WriteData();
			std::cout << '\n';
		}
	}break;

	default: {
		std::cout << "Parametr incorect!\n";
		break;
	}break;
	}
}

void Clear(std::vector<Notebook>& records) {
	char param;
	int index = -1; std::vector<int> indexes;
	std::string str1, str2;
	std::cout << "Enter index(i) or data(d) to clear ";
	std::cin >> param; std::cin.ignore();
	if (param == 'i') {
		std::cout << "Enter index "; std::cin >> index;
	}
	else if (param == 'd') {
		std::cout << "Enter name: "; std::getline(std::cin, str1);
		std::cout << "\nEnter lastname: "; std::getline(std::cin, str2);
		int n = records.size();
		for (int i = 0; i < n; i++) {
			if (records[i].getName() == str1 && records[i].getLastname() == str2)
				if (index == -1) {
					index = i;
					indexes.push_back(i);
				}
				else indexes.push_back(i);
		}
		if (indexes.size() > 1) {
			std::cout << "Enter address: "; std::getline(std::cin, str1);
			n = indexes.size();
			for (int i = 0; i < n; i++) {
				if (records[indexes[i]].getAddress() == str1)
					index = i;
			}
		}
	}
	else std::cout << "\nInput incorect\n";

	records[index].ClearNote();
	std::cout << "This note is clear: \n";
	int n = records.size();
	for (int i = 0; i < n; i++) {
		records[i].WriteShortData();
		std::cout << '\n';
	}

	int flag;
	std::cout << "Do you wont delete this note?\n 1 - yes  2 - no:   ";
	std::cin >> flag; std::cin.ignore();
	if (flag == 1) {
		records.erase(records.begin()+index);
	}

}

void Delete(std::vector<Notebook>& records) {
	char param;
	int index = -1; std::vector<int> indexes;
	std::string str1, str2;
	std::cout << "Enter index(i) or data(d) to clear ";
	std::cin >> param; std::cin.ignore();
	if (param == 'i') {
		std::cout << "Enter index "; std::cin >> index;
	}
	else if (param == 'd') {
		std::cout << "Enter name: "; std::getline(std::cin, str1);
		std::cout << "\nEnter lastname: "; std::getline(std::cin, str2);
		int n = records.size();
		for (int i = 0; i < n; i++) {
			if (records[i].getName() == str1 && records[i].getLastname() == str2)
				if (index == -1) {
					index = i;
					indexes.push_back(i);
				}
				else indexes.push_back(i);
		}
		if (indexes.size() > 1) {
			std::cout << "Enter address: "; std::getline(std::cin, str1);
			n = indexes.size();
			for (int i = 0; i < n; i++) {
				if (records[indexes[i]].getAddress() == str1)
					index = i;
			}
		}
	}

	records.erase(records.begin() + index);
	std::cout << "\nNote was deleted\n ";
}

int main(){

	int key;
	bool toExit = false;
	std::vector<Notebook> notes;

	while(!toExit){

		std::cout << "What do you want to do?\n";
		std::cout << " 1 - add note\n 2 - change note\n 3 - search note\n 4 - sort and show notes\n 5 - show note\n 6 - clear note\n 7 - delete note\n 8 - exit\n";
		std::cin >> key; std::cin.ignore();

		switch (key) {
		case 1: {
			Notebook data; data.AddNote();
			notes.push_back(data);
			std::cout << '\n';
		}break;
		case 2: {
			if (notes.empty()) std::cout << "\nYou have not notes to change!\n";
			else {
				Change(notes);
				std::cout << '\n';
			}
		}break;
		case 3: {
			if (notes.empty()) std::cout << "\nYou have not notes to search!\n";
			else if (notes.size() == 1) {
				std::cout << "\nYou have only one note: \n";
				notes[0].WriteData();
				std::cout << '\n';
			}
			else {
				Search(notes);
				std::cout << '\n';
			}
		}break;
		case 4: {
			if (notes.empty() || notes.size() == 1) std::cout << "\nYou have not notes to sort yet!\n";
			else {
				std::string sortto;
				std::cout << "Sortig order to (name, lastname, address, phone, mail) ";
				std::getline(std::cin, sortto);

				SortData(notes, notes.size()-1, sortto);
				std::cout << '\n';
			}
		}
		case 5: {
			if (notes.empty()) std::cout << "\nYou have not notes yet!\n";
			else {
				char form;
				std::cout << "\nChoose output form: short(s) or full(f)  ";
				std::cin >> form; std::cin.ignore();
				int n = notes.size();
				if (form == 's') {
					for (int i = 0; i < n; i++) {
						notes[i].WriteShortData();
						std::cout << '\n';
					}
				}
				else {
					for (int i = 0; i < n; i++) {
						notes[i].WriteData();
						std::cout << '\n';
					}
				}
				std::cout << '\n';
			}
		}break;
		case 6: {
			if (notes.empty()) std::cout << "\nYou have not notes to clear!\n";
			else {
				Clear(notes);
				std::cout << '\n';
			}
		}break;
		case 7: {
			if (notes.empty()) std::cout << "\nYou have not notes to delete!\n";
			else{
				Delete(notes);
				std::cout << '\n';
			}
		}break;
		case 8: {
			toExit = true;
		}break;
		default: std::cout << "\nIncorect input - try again\n";
		}
	}
	return 0;
}

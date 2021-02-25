#include "Notebook.h"
#include <istream>
#include <string>

//міняє місцями два об'єкти
void Notebook::NoteSwap(Notebook& data)
{
	Notebook temp(data);

	data.name = name;
	data.lastname = lastname;
	data.address = address;
	data.phone = phone;
	data.mail = mail;

	name = temp.name;
	lastname = temp.lastname;
	address = temp.address;
	phone = temp.phone;
	mail = temp.mail;
}


//конструктор з параметрами;
Notebook::Notebook(const std::string& name, const std::string& lastname, const std::string& address, const std::string& phone, const std::string& mail)
{
	this->name = name;
	this->lastname = lastname;
	this->address = address;
	this->phone = phone;
	this->mail = mail;
}
//конструктор copy;
Notebook::Notebook(const Notebook& data)
{
	this->name = data.name;
	this->lastname = data.lastname;
	this->address = data.address;
	this->phone = data.phone;
	this->mail = data.mail;
}


bool Notebook::operator==(const Notebook& note)
{
	if (name == note.name && lastname == note.lastname && address == note.address && phone == note.phone && mail == note.mail)
		return true;
	else 
		return false;
}


//повертає значення полей 
std::string& Notebook::getName()
{
	return name;
}

std::string& Notebook::getLastname()
{
	return lastname;
}

std::string& Notebook::getAddress()
{
	return address;
}

std::string& Notebook::getPhone()
{
	return phone;
}

std::string& Notebook::getMail()
{
	return mail;
}


//додає вказані дані 
void Notebook::AddNote(const std::string& name, const std::string& lastname, const std::string& address, const std::string& phone, const std::string& mail)
{
	this->name = name;
	this->lastname = lastname;
	this->address = address;
	this->phone = phone;
	this->mail = mail;
}
//додає дані з клавіатури
void Notebook::AddNote() {
	std::cout << "Enter data for note\n";
	std::cout << "Name: "; std::getline(std::cin, name); 
	std::cout << "Lastame: "; std::getline(std::cin, lastname);
	std::cout << "Address: "; std::getline(std::cin, address);
	std::cout << "Phone: "; std::getline(std::cin, phone);
	std::cout << "Mail: "; std::getline(std::cin, mail);
}


//знищення;
void Notebook::ClearNote()
{
	name = "";
	lastname = "";
	address = "";
	phone = "";
	mail = "";
}

//виведення інформації на екран;
void Notebook::WriteData() const
{
	std::cout << "\nName: " << name << " " << lastname;
	std::cout << "\nAddress: " << address << "\nPhone: " << phone << "\nE-Mail: " << mail;
}
//виведення на екран скороченої інформації
void Notebook::WriteShortData() const
{
	std::cout << "\nName: " << name << " " << lastname;
	std::cout << "\nPhone: " << phone << '\n';
}

//редагування записів;
void Notebook::ChangeNote(const std::string& changer, std::string& data)
{
	if (changer == "name") name = data;
	else if (changer == "lastname") lastname = data;
	else if (changer == "address") address = data;
	else if (changer == "phone") phone = data;
	else if (changer == "mail") mail = data;
	else std::cout << "\nChange error\n";
}



//пошук потрібної інформації за співпадінням;
int SearchNote(const Notebook data, std::vector<Notebook> records, int size)
{
	int index = -1;
	for (int i = 0; i < size; i++) {
		if (records[i] == data) return i;
	}

	return index;
}

//пошук потрібної інформації за ім'ям;
std::vector<int> SearchName(const std::string name, std::vector<Notebook> records, int size, int returnNumber)
{
	std::vector<int> index;

	for (int i = 0; i < size; i++) {
		if (records[i].getName() == name && returnNumber > 0) {
			index.push_back(i);
			returnNumber--;
		}
		if (returnNumber == 0) break;
	}

	return index;
}

//пошук потрібної інформації за прізвищем;
std::vector<int> SearchLastname(const std::string lastname, std::vector<Notebook> records, int size, int returnNumber)
{
	std::vector<int> index;

	for (int i = 0; i < size; i++) {
		if (records[i].getLastname() == lastname && returnNumber > 0) {
			index.push_back(i);
			returnNumber--;
		}
		if (returnNumber == 0) break;
	}

	return index;
}

//пошук потрібної інформації за адресою;
std::vector<int> SearchAddress(const std::string address, std::vector<Notebook> records, int size, int returnNumber)
{
	std::vector<int> index;

	for (int i = 0; i < size; i++) {
		if (records[i].getAddress() == address && returnNumber > 0) {
			index.push_back(i);
			returnNumber--;
		}
		if (returnNumber == 0) break;
	}

	return index;
}

//пошук потрібної інформації за телефоном;
int SearchPhone(const std::string phone, std::vector<Notebook> records, int size)
{
	int index = -1;

	for (int i = 0; i < size; i++) {
		if (records[i].getPhone() == phone) {
			return i; //повертає індекс об'єкта де співпав номер телефону
		}
	}

	return index; //повертає -1 якщо потрібного запису не знайдено
}


//сортування за різними полями.
void SortData(std::vector<Notebook>& records, int size, const std::string sortflag)
{
	if (sortflag == "name") { //сортує за ім'ям
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (records[j].getName() > records[j + 1].getName())
					records[j].NoteSwap(records[j + 1]);
			}
		}
	}
	else if (sortflag == "lastname") { //сортує за прізвищем
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (records[j].getLastname() > records[j + 1].getLastname())
					records[j].NoteSwap(records[j + 1]);
			}
		}
	}
	else if (sortflag == "address") {//сортує за адресою
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (records[j].getAddress() > records[j + 1].getAddress())
					records[j].NoteSwap(records[j + 1]);
			}
		}
	}
	else if (sortflag == "phone") { //сортує за номером телефону
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (records[j].getPhone() > records[j + 1].getPhone())
					records[j].NoteSwap(records[j + 1]);
			}
		}
	}
	else if (sortflag == "mail") { //сортує за e-mail
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i; j++) {
				if (records[j].getMail() > records[j + 1].getMail())
					records[j].NoteSwap(records[j + 1]);
			}
		}
	}
	else std::cout << "\nSorting error\n";//виводить повідомлення про помилку якщо параметр сортування не відповідний
}

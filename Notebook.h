#pragma once

#include <string.h>
#include <iostream>
#include <vector>

class Notebook
{
	std::string name;
	std::string lastname;
	std::string address;
	std::string phone;
	std::string mail;


	

public:
	//конструктори без параметрів та з параметрами;
	Notebook() {
		name = "";
		lastname = "";
		address = "";
		phone = "";
		mail = "";
	}
	
	Notebook(const std::string& name, const std::string& lastname, const std::string& address, const std::string& phone, const std::string& mail);
	Notebook(const Notebook& data);

	bool operator==(const Notebook& note);

	std::string& getName();// повертає ім'я з запису
	std::string& getLastname();// повертає прізвище з запису
	std::string& getAddress();// повертає адресу з запису
	std::string& getPhone();// повертає телефон з запису
	std::string& getMail();// повертає пошту з запису
	
	void NoteSwap(Notebook& data);//міняє місцями дані об'єктів

	//додавання;
	void AddNote(const std::string& name, const std::string& lastname, const std::string& address, const std::string& phone, const std::string& mail);
	void AddNote();

	//знищення;
	void ClearNote();

	//виведення інформації на екран;
	void WriteData()const;

	void WriteShortData()const;//виводить лише ім'я і номер телефону
	
	//редагування записів;
	void ChangeNote(const std::string& changer, std::string& data);

};


int SearchNote(const Notebook data, std::vector<Notebook> records, int size);

//пошук потрібної інформації за ім'ям;
std::vector<int> SearchName(const std::string name, std::vector<Notebook> records, int size, int returnNumber);

//пошук потрібної інформації за прізвищем;
std::vector<int> SearchLastname(const std::string lastname, std::vector<Notebook> records, int size, int returnNumber);

//пошук потрібної інформації за адресою;
std::vector<int> SearchAddress(const std::string address, std::vector<Notebook> records, int size, int returnNumber);

//пошук потрібної інформації за телефоном;
int SearchPhone(const std::string phone, std::vector<Notebook> records, int size);

//сортування за різними полями.
void SortData(std::vector<Notebook>& records, int size, const std::string sortflag);


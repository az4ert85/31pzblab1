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
	//������������ ��� ��������� �� � �����������;
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

	std::string& getName();// ������� ��'� � ������
	std::string& getLastname();// ������� ������� � ������
	std::string& getAddress();// ������� ������ � ������
	std::string& getPhone();// ������� ������� � ������
	std::string& getMail();// ������� ����� � ������
	
	void NoteSwap(Notebook& data);//���� ������ ��� ��'����

	//���������;
	void AddNote(const std::string& name, const std::string& lastname, const std::string& address, const std::string& phone, const std::string& mail);
	void AddNote();

	//��������;
	void ClearNote();

	//��������� ���������� �� �����;
	void WriteData()const;

	void WriteShortData()const;//�������� ���� ��'� � ����� ��������
	
	//����������� ������;
	void ChangeNote(const std::string& changer, std::string& data);

};


int SearchNote(const Notebook data, std::vector<Notebook> records, int size);

//����� ������� ���������� �� ��'��;
std::vector<int> SearchName(const std::string name, std::vector<Notebook> records, int size, int returnNumber);

//����� ������� ���������� �� ��������;
std::vector<int> SearchLastname(const std::string lastname, std::vector<Notebook> records, int size, int returnNumber);

//����� ������� ���������� �� �������;
std::vector<int> SearchAddress(const std::string address, std::vector<Notebook> records, int size, int returnNumber);

//����� ������� ���������� �� ���������;
int SearchPhone(const std::string phone, std::vector<Notebook> records, int size);

//���������� �� ������ ������.
void SortData(std::vector<Notebook>& records, int size, const std::string sortflag);


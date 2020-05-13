#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "functions.h"
#include <vector>
#include <sstream>

using namespace std;

TCHAR* header()
{
	stringstream ss;
	ss << setw(10) << "����" << setw(10) << "�������"
		<< setw(20) << "������ ��������" << setw(20) << "������ ��������"
		<< setw(20) << "������ ��������" << setw(12) << "�� ��������";
	char str[MAX_PATH];
	strcpy(str, ss.str().c_str());
	return str;
}

TCHAR* entryToString(Entry entry)
{
	stringstream ss;
	ss << setw(10) << entry.key << setw(10) << entry.age
		<< setw(20) << entry.firstAnimal << setw(20) << entry.secondAnimal
		<< setw(20) << entry.thirdAnimal << setw(12) << (entry.toDelete ? "��" : "���");
	char str[MAX_PATH];
	strcpy(str, ss.str().c_str());
	return str;
}

TCHAR* animalToString(Animal animal)
{
	stringstream ss;
	ss << animal.amount << " ��� ����������� \""
		<< animal.animal << "\";" << endl;
	char str[120];
	strcpy(str, ss.str().c_str());
	return str;
}

void readEntry(HANDLE hFile, char* key, Entry& entry)
{
	if (findKey(hFile, key)) {
		SetFilePointer(hFile, -(int)sizeof(Entry), NULL, FILE_CURRENT);
		ReadFile(hFile, (char*)(&entry), sizeof(Entry), NULL, NULL);
	}
}

void readAll(HANDLE hFile, vector<Entry>* entriesList)
{
	int position = 0;
	Entry buffer;

	while (true) {
		DWORD pointer = SetFilePointer(hFile, position * sizeof(Entry), NULL, FILE_BEGIN);

		if (pointer == GetFileSize(hFile, NULL)) {
			break;
		}

		ReadFile(hFile, (char*)(&buffer), sizeof(Entry), NULL, NULL);
		position++;
		entriesList->push_back(buffer);
	}

	if (entriesList->size() == 0) {
		cout << "� ����� �����!" << endl;
	}
}
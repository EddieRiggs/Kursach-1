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
	ss << setw(10) << "Ключ" << setw(10) << "Возраст"
		<< setw(20) << "Первое животное" << setw(20) << "Второе животное"
		<< setw(20) << "Третье животное" << setw(12) << "На удаление";
	char str[MAX_PATH];
	strcpy(str, ss.str().c_str());
	return str;
}

TCHAR* entryToString(Entry entry)
{
	stringstream ss;
	ss << setw(10) << entry.key << setw(10) << entry.age
		<< setw(20) << entry.firstAnimal << setw(20) << entry.secondAnimal
		<< setw(20) << entry.thirdAnimal << setw(12) << (entry.toDelete ? "да" : "нет");
	char str[MAX_PATH];
	strcpy(str, ss.str().c_str());
	return str;
}

TCHAR* animalToString(Animal animal)
{
	stringstream ss;
	ss << animal.amount << " раз встретилось \""
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
		cout << "В файле пусто!" << endl;
	}
}
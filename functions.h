#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
#include "Resource.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ������� ������ ������ � ����
void writeEntry(HANDLE hFile, Entry newEntry);

// ������� ������ ����� ������
void readEntry(HANDLE hFile, char* key, Entry& entry);

// ������� ������ ���� �������
void readAll(HANDLE hFile, vector<Entry>* entriesList);

// ������� ������ ����� ������
TCHAR* header();
TCHAR* entryToString(Entry entry);
TCHAR* animalToString(Animal animal);

// ������� ������ ����� � �����
bool findKey(HANDLE hFile, char* key);

// ������� ����� ����� �� ��������
void changeSelection(HANDLE hFile, char* key);

// ������� �������� ���������� �������
void deleteSelectedEntries(HANDLE &hFile, TCHAR* fileName);

// ������� �������������� ������
void editEntry(HANDLE hFile, char* key, Entry newEntry);

// ������� ���������� ����� ���������� ���������
void findMostPopular(HANDLE hFile, vector<Animal>& animals);

// ����������� ��� ������� ������
bool findAnimalInList(char* animal, vector<Animal>* animals);
vector<Animal> addEntry(Entry entry, vector<Animal> animals);
vector<Animal> getMostPopular(vector<Animal>* animals);
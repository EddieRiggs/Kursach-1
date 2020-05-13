#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
#include "Resource.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функция записи строки в файл
void writeEntry(HANDLE hFile, Entry newEntry);

// Функция чтения одной записи
void readEntry(HANDLE hFile, char* key, Entry& entry);

// Функция чтения всех записей
void readAll(HANDLE hFile, vector<Entry>* entriesList);

// Функция вывода одной записи
TCHAR* header();
TCHAR* entryToString(Entry entry);
TCHAR* animalToString(Animal animal);

// Функция поиска ключа в файле
bool findKey(HANDLE hFile, char* key);

// Функция смены меток на удаление
void changeSelection(HANDLE hFile, char* key);

// Функция удаления помеченных записей
void deleteSelectedEntries(HANDLE &hFile, TCHAR* fileName);

// Функция редактирования записи
void editEntry(HANDLE hFile, char* key, Entry newEntry);

// Функция нахождения самых популярных животинок
void findMostPopular(HANDLE hFile, vector<Animal>& animals);

// Обработчики для функции поиска
bool findAnimalInList(char* animal, vector<Animal>* animals);
vector<Animal> addEntry(Entry entry, vector<Animal> animals);
vector<Animal> getMostPopular(vector<Animal>* animals);
#include "functions.h"

using namespace std;

void editEntry(HANDLE hFile, char* key, Entry newEntry)
{
	Entry entry;
	if (findKey(hFile, key)) {

		SetFilePointer(hFile, -(int)sizeof(Entry), NULL, FILE_CURRENT);
		WriteFile(hFile, reinterpret_cast<const char*>(&newEntry), sizeof(Entry), NULL, NULL);
	}
}
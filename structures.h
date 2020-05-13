#pragma once
#include "Resource.h"

struct Entry {
    int age;
    char firstAnimal[20];
    char secondAnimal[20];
    char thirdAnimal[20];
    char key[20];
    bool toDelete;
};

struct Animal {
    int amount;
    char animal[20];
};
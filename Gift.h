#ifndef GIFT_H
#define GIFT_H
#include <iostream>
#include <ostream>
#include <string.h>
#include "ToyClass.h"
using namespace std;
class Gift
{
private:
    char *name, *destination, *personName;
    ToyClass *toys;
    int toysLength;

public:
    Gift(const char *_name = "undefined", const char *_destination = "undefined", const char *_personName = "undefined", ToyClass *_toys = {}, int _toysLength = 0)
    {

        name = new char[strlen(_name)];
        destination = new char[strlen(_destination)];
        personName = new char[strlen(_personName)];
        toysLength = _toysLength;
        toys = new ToyClass[toysLength];
        strcpy(name, _name);
        strcpy(personName, _personName);
        strcpy(destination, _destination);
        for (int i = 0; i < toysLength; i++)
            toys[i] = _toys[i];
    }

    Gift(const Gift &obj)
    {
        delete[] name;
        delete[] destination;
        delete[] toys;
        delete[] personName;
        toysLength = obj.toysLength;
        name = new char[strlen(obj.name)];
        destination = new char[strlen(obj.destination)];
        personName = new char[strlen(obj.personName)];
        toys = new ToyClass[obj.toysLength];
        strcpy(name, obj.name);
        strcpy(destination, obj.name);
        strcpy(personName, obj.personName);
        for (int i = 0; i < toysLength; i++)
            toys[i] = obj.toys[i];
    }

    Gift &operator=(const Gift &obj)
    {
        delete[] name;
        delete[] destination;
        delete[] toys;
        delete[] personName;
        toysLength = obj.toysLength;
        name = new char[strlen(obj.name)];
        destination = new char[strlen(obj.destination)];
        personName = new char[strlen(obj.personName)];
        toys = new ToyClass[obj.toysLength];
        strcpy(name, obj.name);
        strcpy(destination, obj.name);
        strcpy(personName, obj.personName);
        for (int i = 0; i < toysLength; i++)
            toys[i] = obj.toys[i];
        return *this;
    }

    const char *getName()
    {
        return name;
    }
    const char *getDestination()
    {
        return destination;
    }
    void afisare()
    {
        cout << endl
             << toysLength << endl;
        cout << "Numele cadoului este: " << name << " cu destinatia " << destination << "pentru persoana " << personName << endl
             << "Jucariile sunt: " << endl;
        for (int i = 0; i < toysLength; i++)
        {
            toys[i].afisare();
        }
    }
    ~Gift()
    {
        delete[] name;
        delete[] destination;
        delete[] toys;
        delete[] personName;
    }
};
#endif
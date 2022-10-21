#ifndef TOYCLASS_J
#define TOYCLASS_J
#include <iostream>
#include <ostream>
#include <string.h>
using namespace std;
class ToyClass
{
private:
    char *name = new char[1], *category = new char[1];
    float price, weight, age;

public:
    ToyClass(const char *_name = "undefined", float _price = 0, float _weight = 0, const char *_category = "none", int _age = 3)
    {
        delete[] name;
        delete[] category;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        category = new char[strlen(_category) + 1];
        strcpy(name, _category);
        price = _price;
        weight = _weight;
        age = _age;
    }

    ToyClass(const ToyClass &obj)
    {
        delete[] name;
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        price = obj.price;
        weight = obj.weight;
    }

    ToyClass &operator=(const ToyClass &obj)
    {
        delete[] name;
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        price = obj.price;
        weight = obj.weight;
        return *this;
    };

    const char *getName()
    {
        return name;
    }
    float getPrice()
    {
        return price;
    }
    float getWeight()
    {
        return weight;
    }
    void afisare()
    {

        cout << "Numele jucariei este: " << name << " cu pretul de " << price << " si greutate de " << weight << endl;
    }
    ~ToyClass()
    {

        delete[] name;
    }
};
#endif
#ifndef INTERFACE_H
#define INTERFACE_H
#include <ostream>
#include <string.h>
#include "ToyClass.h"
void InteractionInterface(char *&nameGift, char *&destination, char *&personName, ToyClass *&toys, int &toysLength)
{

    int price, weight, age;
    char *nameToy = new char[50], *category = new char[50];
    cout << "Introduceti numele cadoului. (alegeti un nume sugestiv si fara spatii)\n";
    cin.ignore();
    cin.getline(nameGift, 50);
    cout << "Introduceti destinatia cadoului.\n";
    cin.getline(destination, 50);
    cout << "Introduceti destinatarului.\n";
    cin.getline(personName, 50);
    cout << "Introduceti numarul de jucarii pe care vreti sa il adaugati initial. \n";
    cin >> toysLength;

    for (int j = 0; j < toysLength; j++)
    {
        cout << "**************Jucaria numarul: "
             << "**************\n**********************" << j + 1 << "**********************\nIntroduceti numele jucariei\n";
        cin.ignore();
        cin.getline(nameToy, 50);
        cout << "Introduceti pretul jucariei.\n";
        cin >> price;
        cout << "Introduceti greutate.\n";
        cin >> weight;
        cout << "Introduceti categoria\n";
        cin.ignore();
        cin.getline(category, 50);
        cout << "Introduceti varsta recomandata.\n";
        cin >> age;
        toys[j] = ToyClass(nameToy, price, weight, category, age);
        }
}
#endif
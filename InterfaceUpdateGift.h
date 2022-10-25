#ifndef INTERFACE_UPDATE_H
#define INTERFACE_UPDATE_H
#include "Gift.h"
#include "ToyClass.h"
void interfaceUpdate(Gift *&allCustomGifts)
{
    char *nameGift = new char[50], *destination = new char[50], *personName = new char[50];
    int j, giftNumber;
    cout << "Ce cadou vreti sa modificati?\n";
    cin >> giftNumber;
    do
    {
        cout << "Ce parametru doriti sa modificati?\n1.Nume cadou\n2.Destinatie cadou\n3.Destinatar cadou\n4.Adaugare jucarie noua\n0.Exit\n";
        cin >> j;

        switch (j)
        {
        case 1:
        {
            cout << "Introduceti noul nume.\n";
            cin.ignore();
            cin.getline(nameGift, 50);
            allCustomGifts[giftNumber - 1].setName(nameGift);
            break;
        }
        case 2:
        {

            cout << "Introduceti noua destinatie.\n";
            cin.ignore();
            cin.getline(destination, 50);
            allCustomGifts[giftNumber - 1].setDestination(destination);
            break;
        }
        case 3:
        {

            cout << "Introduceti noul destinatar.\n";
            cin.ignore();
            cin.getline(personName, 50);
            allCustomGifts[giftNumber - 1].setPersonName(personName);
            break;
        }
        case 4:
        {
            int price, weight, age, updateToysLength = allCustomGifts[giftNumber - 1].getToysLength() + 1;
            char *nameToy = new char[50], *category = new char[50];
            ToyClass *auxToys = new ToyClass[updateToysLength];

            for (int k = 0; k < updateToysLength - 1; k++)
            {
                auxToys[k] = allCustomGifts[giftNumber - 1].getToys()[k];
            }
            cout << "**************Jucaria numarul: "
                 << "**************\n**********************" << updateToysLength << "**********************\nIntroduceti numele jucariei\n";
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
            auxToys[updateToysLength - 1] = ToyClass(nameToy, price, weight, category, age);
            allCustomGifts[giftNumber - 1].setToys(auxToys, updateToysLength);
            break;
        }
        default:
            return;
            break;
        }
    } while (j != 0);
}
#endif
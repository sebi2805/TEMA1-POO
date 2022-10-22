#include <ostream>
#include <string.h>
#include "ToyClass.h"
#include "Gift.h"
#include "InterfaceInteraction.h"
using namespace std;

int main()
{
    int i = 1, toysLength, numberOfGifts = 0;
    char *nameGift = new char[50], *destination = new char[50], *personName = new char[50];
    Gift *allCustomGifts = new Gift[10];
    Gift customGift;
    ToyClass *toys = new ToyClass[10];
    cout << "*******************************************CONFIGURARE CADOU*******************************************" << endl;
    do
    {
        cout << "1.Start configurare cadou\n2.Printare cadou\n3.Adaugare cadou nou\n4.Stergere cadou\n5.Modificare cadou existent\n6.Clear\n0.Exit\n";
        cin >> i;
        switch (i)
        {
        case 0:
            cout << "Iesire interfata";
            break;

        case 1:
        {
            InteractionInterface(nameGift, destination, personName, toys, toysLength);
            allCustomGifts[numberOfGifts] = Gift(nameGift, destination, personName, toys, toysLength);
            numberOfGifts++;
            break;
        }

        case 2:
        {
            if (numberOfGifts == 0)
                cout << "Configurati primul cadou\n";
            else
            {
                int j;
                cout << "Ce cadou vrei sa afisezi?\n";
                cin >> j;
                if (j <= numberOfGifts)
                    allCustomGifts[j - 1].afisare();
                else
                    cout << "Ne pare rau acest cadou nu exista.\n";
            }
            break;
        }
        case 3:
        {

            InteractionInterface(nameGift, destination, personName, toys, toysLength);
            allCustomGifts[numberOfGifts] = Gift(nameGift, destination, personName, toys, toysLength);
            numberOfGifts++;
            break;
        }

        case 4:
        {
            int j;
            cout << "Ce cadou doriti sa stergeti?\n";
            cin >> j;
            if (j < numberOfGifts)
            {
                cout << "seterger" << j - 1 << numberOfGifts - 1;
                for (int k = j - 1; j < numberOfGifts; j++)
                {
                    cout << "Pasul" << k << endl;
                    allCustomGifts[k] = allCustomGifts[k + 1];
                    cout << "Stergere completa. \n";
                    numberOfGifts--;
                }
            }
            else if (j == numberOfGifts)
                numberOfGifts--;
            else
                cout << "Ne pare rau acest cadou nu exista.\n";
            break;
        }
        case 5:
        {
            int j, giftNumber;
            cout << "Ce cadou vreti sa modificati?\n";
            cin >> giftNumber;
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
            }
            break;
        }
        case 6:
        {
            system("clear");
            break;
        }
        default:
            break;
        }
    } while (i != 0);
    return 0;
}

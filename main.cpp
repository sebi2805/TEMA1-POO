#include <ostream>
#include <string.h>
#include "ToyClass.h"
#include "Gift.h"
#include "InterfaceInteraction.h"
#include "InterfaceUpdateGift.h"
using namespace std;

int main()
{
    int i = 1, toysLength, numberOfGifts = 0;
    char *nameGift = new char[50], *destination = new char[50], *personName = new char[50];
    Gift *allCustomGifts = new Gift[10];
    Gift customGift;
    ToyClass test("sebi", 0, 1, "s", 1);
    cout << test;
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
            interfaceUpdate(allCustomGifts);
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

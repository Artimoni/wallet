#include <iostream>
#include "Purse.h"

int main() {
    Dollar::setRate(82.5);
    Euro::setRate(95.2);
    Pound::setRate(108.8); //курс на 12.05

    Purse myPurse; //кошель

    myPurse.fillRandom(3); //стартовое наполнение

    int choice;
    do {
        std::cout << "\nwallet\n";
        std::cout << "1. Show wallet\n";
        std::cout << "2. Show total in rubles\n";
        std::cout << "3. Show history\n";
        std::cout << "4. Add currency manually\n";
        std::cout << "5. Remove last currency\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            myPurse.printAll();
        }
        else if (choice == 2) {
            std::cout << "Total in rubles: " << myPurse.totalInRubles() << "₽\n";
        }
        else if (choice == 3) {
            myPurse.printHistory();
        }
        else if (choice == 4) {
            int type;
            double amount;
            std::cout << "Enter currency type (0 - Dollar, 1 - Euro, 2 - Pound): ";
            std::cin >> type;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            myPurse.addCurrency(type, amount);
        }
        else if (choice == 5) {
            myPurse.removeLast();
        }

    } while (choice != 0);

    return 0;
}

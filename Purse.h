#pragma once
#include "Currency.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Purse {
    std::vector<Currency*> currencies;
    std::vector<std::string> history;
public:
    Purse();
    ~Purse();
    void fillRandom(int count); //случайное наполнение
    void printAll() const;
    double totalInRubles() const; //итоговая сумма в рублях и вывод
    void printHistory() const;
    void addCurrency(int type, double amount); // 0 - Dollar, 1 - Euro, 2 - Pound
    void removeLast(); // удаление последней валюты
};

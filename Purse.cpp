#include "Purse.h"

//ставим по умолчанию
double Dollar::rate = 82.5;
double Euro::rate = 95.2;
double Pound::rate = 108.8;

Purse::Purse() {
    std::srand(std::time(nullptr)); //инициализация генерирования случайных чисел
}

Purse::~Purse() {
    for (Currency* c : currencies)
        delete c; //деконструктор для удаления из динамической памяти(учёл ошибку про умные указатели)
}

void Purse::fillRandom(int count) {
    for (int i = 0; i < count; ++i) {
        int type = std::rand() % 3;
        double amount = 1 + std::rand() % 100; //случайная сумма валют от 1 до 100

        Currency* currency = nullptr;
        std::string record;

        if (type == 0) {
            currency = new Dollar(amount);
            record = "Added " + std::to_string(amount) + " Dollars";
        }
        else if (type == 1) {
            currency = new Euro(amount);
            record = "Added " + std::to_string(amount) + " Euros";
        }
        else {
            currency = new Pound(amount);
            record = "Added " + std::to_string(amount) + " Pounds";
        }

        currencies.push_back(currency);
        history.push_back(record);
    }
}

void Purse::printAll() const {
    for (Currency* c : currencies)
        c->print();
}

double Purse::totalInRubles() const {
    double sum = 0.0;
    for (Currency* c : currencies)
        sum += c->toRubles();
    return sum; //считывание общих 
}

void Purse::printHistory() const {
    std::cout << "History of additions:\n";
    for (const std::string& h : history)
        std::cout << h << std::endl;
}

void Purse::addCurrency(int type, double amount) {
    Currency* currency = nullptr;
    std::string record;

    if (type == 0) {
        currency = new Dollar(amount);
        record = "Manually added " + std::to_string(amount) + " Dollars";
    }
    else if (type == 1) {
        currency = new Euro(amount);
        record = "Manually added " + std::to_string(amount) + " Euros";
    }
    else if (type == 2) {
        currency = new Pound(amount);
        record = "Manually added " + std::to_string(amount) + " Pounds";
    }
    else {
        std::cout << "Invalid currency type!\n";
        return;
    }

    currencies.push_back(currency);
    history.push_back(record);
}

void Purse::removeLast() {
    if (!currencies.empty()) {
        Currency* last = currencies.back();
        currencies.pop_back();
        delete last;
        history.push_back("Removed last added currency");
    }
    else {
        std::cout << "Purse is already empty!\n";
    }
}

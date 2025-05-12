#pragma once
#include <iostream>

class Currency {
protected:
    double amount;
public:
    Currency(double amt) : amount(amt) {}
    virtual ~Currency() {}
    virtual double toRubles() const = 0;
    virtual void print() const = 0;
};

class Dollar : public Currency {
    static double rate; //курс к нынешнему рублю
public:
    Dollar(double amt) : Currency(amt) {}
    static void setRate(double r) { rate = r; }
    double toRubles() const override { return amount * rate; } //перевод к нынешнему рублю
    void print() const override { //вывод 
        std::cout << "Dollar: " << amount << " ($), " << amount * 100 << " cents\n";
    }
}; //для дальнейших классов аналогично

class Euro : public Currency {
    static double rate;
public:
    Euro(double amt) : Currency(amt) {}
    static void setRate(double r) { rate = r; }
    double toRubles() const override { return amount * rate; }
    void print() const override {
        std::cout << "Euro: " << amount << " (€), " << amount * 100 << " cents\n";
    }
};

class Pound : public Currency {
    static double rate;
public:
    Pound(double amt) : Currency(amt) {}
    static void setRate(double r) { rate = r; }
    double toRubles() const override { return amount * rate; }
    void print() const override {
        std::cout << "Pound: " << amount << " (£), " << amount * 100 << " pence\n";
    }
};

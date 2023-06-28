
#ifndef ATM_H
#define ATM_H

class ATM {
private:
    int pin;
    int balance;

public:
    ATM(int p, int b);

    int withdraw();
    int cash_transfer();
    int check_balance();
    int cash_deposit();
    int change_pin();
    int account(long long int n);

    void savePinToFile();
    void readPinFromFile();
};

#endif



// main.cpp

#pragma once

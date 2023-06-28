
#include "ATM.h"
#include <iostream>
#include <fstream>

using namespace std;

ATM::ATM(int p, int b) {
    pin = p;
    balance = b;
}

void ATM::savePinToFile() {
    ofstream file("pin.txt");
    if (file.is_open()) {
        file << pin;
        file.close();
    }
}

void ATM::readPinFromFile() {
    ifstream file("pin.txt");
    if (file.is_open()) {
        file >> pin;
        file.close();
    }
}

int ATM::withdraw() {
    int a, c;
    cout << "Please Enter Your 4-digit PIN: ";
    cin >> a;
    if (a == pin) {
        cout << "Please Enter the Amount: ";
        cin >> c;
        if (c % 500 == 0) {
            if (c <= balance) {
                balance = balance - c;
                cout << "Your Transaction is completed Successfully!!!" << endl;
                cout << "Your current balance is: " << balance;
            }
            else {
                cout << "You have insufficient balance!" << endl;
            }
        }
        else {
            cout << "You entered an incorrect amount! Amount must be in multiples of 500!" << endl;
            withdraw();
        }
    }
    else {
        char a;
        cout << "Your PIN is wrong!" << endl;
        cout << "Do you want to perform another transaction (press Y or N): ";
        cin >> a;
        if (a == 'Y') {
            withdraw();
        }
        else {
            cout << "Your PIN is wrong. Try again next time!" << endl << "Take your Card....";
        }
    }
    return 0;
}

int ATM::cash_transfer() {
    int a, b;
    long long int acc;
    cout << "Enter Your PIN: ";
    cin >> a;
    if (a == pin) {
        cout << "Please Enter the 11-digit Account Number (it must start from 0): ";
        cin >> acc;
        while (account(acc) != 11) {
            cout << "Invalid account!" << endl;
            cout << "Enter Your Account Number Again: ";
            cin >> acc;
        }
    }
    else {
        cout << "Wrong PIN!!";
        cash_transfer();
    }
    cout << "Please Enter How many Rupees You want to transfer: ";
    cin >> b;
    if (b <= balance) {
        balance = balance - b;
        cout << "Your Cash is transferred successfully!" << endl;
        cout << "Your Remaining Balance is: " << balance;
    }
    else {
        cout << "Balance low!" << endl;
        cash_transfer();
    }
    return 0;
}

int ATM::check_balance() {
    int p;
    cout << "Please Enter your PIN: ";
    cin >> p;
    if (p == pin) {
        cout << "Your Balance is: " << balance;
    }
    else {
        cout << "Wrong PIN!";
    }
    return 0;
}

int ATM::cash_deposit() {
    int deposit, p;
    cout << "Enter PIN: ";
    cin >> p;
    if (p == pin) {
        cout << "How many Rupees You Want to deposit: ";
        cin >> deposit;
        balance += deposit;
        cout << "Now Your Balance is: " << balance;
    }
    else {
        cout << "Wrong PIN!";
        cash_deposit();
    }
    return 0;
}

int ATM::change_pin() {
    int oldPin, newPin;
    cout << "Please Enter your current PIN: ";
    cin >> oldPin;
    if (oldPin == pin) {
        cout << "Please Enter the New PIN: ";
        cin >> newPin;
        pin = newPin;
        savePinToFile();
    }
    else {
        cout << "Wrong PIN!";
        change_pin();
    }
    cout << "Your New PIN is: " << pin;
    return 0;
}

int ATM::account(long long int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count + 1;
}
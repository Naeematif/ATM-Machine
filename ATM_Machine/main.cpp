#include "ATM.h"
#include<iostream>
using namespace std;

int main() {
    ATM obj(1234, 3000);
    int n;
    char c;
    do {

        cout << "Which function do you want to use:" << endl;
        cout << "1. Cash Withdrawal" << endl;
        cout << "2. Cash Transfer" << endl;
        cout << "3. Cash Deposit" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Change PIN" << endl;
        cout << "6. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> n;
        obj.readPinFromFile();                        // Read the PIN from file

        switch (n) {
        case 1:
            obj.withdraw();
            break;
        case 2:
            obj.cash_transfer();
            break;
        case 3:
            obj.cash_deposit();
            break;
        case 4:
            obj.check_balance();
            break;
        case 5:
            obj.change_pin();
            break;
        case 6:
            break;
        default:
            cout << "Wrong Choice!";
        }
        cout << "\nDo you want to perform another transaction:";
        cin >> c;
    }

    while (c == 'Y' || c == 'y');


    obj.savePinToFile();                          // Save the PIN to file for the next execution
    return 0;
}
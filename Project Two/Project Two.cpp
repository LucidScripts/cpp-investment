#include "InvestmentData.h"
#include <iostream>
#include <iomanip> 
using namespace std;

int checkValidInput(const string& prompt) { // Function to prompt for number and check validity
    int number;
    cout << prompt;
    cin >> number;
    while (cin.fail() || number < 0) {
        cin.clear(); // Clear error flags from cin
        cin.ignore(1000, '\n');
        cout << "Please enter a valid, non-negative number: ";
        cin >> number;
    }
    return number;
}


void displayReport(const InvestmentData& Investment) { // Outputs a year-by-year breakdown of balances with and without monthly deposits
    // using accesor functions from Investment to receive variables
    int initial = Investment.getInitialAmount();
    int monthly = Investment.getMonthlyDeposit();
    int interest = Investment.getAnnualInterest();
    int years = Investment.getNumberOfYears();

    // initialize needed variables
    double yearEndInterest;
    double monthlyInterest;
    double balance;

    balance = initial;

    cout << "   Balance and Interest Without Additional Monthly Deposits\n";
    cout << "============================================================\n";
    cout << left << setw(10) << "Year"
        << setw(28) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 1; i <= years; i++) { // loop to generate without monthly deposits
        yearEndInterest = balance * (interest / 100.0);
        balance += yearEndInterest;
        cout << setw(10) << i
            << "$" << setw(27) << fixed << setprecision(2) << balance
            << "$" << fixed << setprecision(2) << yearEndInterest << endl;
    }

    cout << endl;

    cout << "   Balance and Interest With Additional Monthly Deposits\n";
    cout << "============================================================\n";
    cout << left << setw(10) << "Year"
        << setw(28) << "Year End Balance"
        << "Year End Earned Interest" << endl;
    cout << "------------------------------------------------------------\n";

    balance = initial;  // Reset balance for this section

    for (int i = 1; i <= years; i++) {
        yearEndInterest = 0.0;  // Reset yearly interest

        for (int m = 1; m <= 12; m++) { // Loop to generate with monthly deposits
            balance += monthly;
            monthlyInterest = balance * ((interest / 100.0) / 12.0);
            yearEndInterest += monthlyInterest;
            balance += monthlyInterest;
        }

        cout << setw(10) << i
            << "$" << setw(27) << fixed << setprecision(2) << balance
            << "$" << fixed << setprecision(2) << yearEndInterest << endl;
    }
}



void displayMenu() { // Prompts the user for investment data and displays the report
    InvestmentData Investment; // declare class

    int amount, deposit, interest, years;
    char key;

    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;

    amount = checkValidInput("Initial Investment Amount: $");
    Investment.setInitialAmount(amount);

    deposit = checkValidInput("Monthly Deposit: $");
    Investment.setMonthlyDeposit(deposit);

    interest = checkValidInput("Annual Interest: %");
    Investment.setAnnualInterest(interest);

    years = checkValidInput("Number of years: ");
    Investment.setNumberOfYears(years);

    displayReport(Investment);
}






int main()
{
    string option;
    displayMenu();

    while (option != "q" && option != "Q") {
        cout << "Type Q to quit or anything else to view a different interest chart...";
        cin >> option;

        if (option != "q" && option != "Q") {
            displayMenu();
        }
    }
}


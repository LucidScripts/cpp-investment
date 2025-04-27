#include "InvestmentData.h"

InvestmentData::InvestmentData() { // Constructor class
    initialAmount = 0;
    monthlyDeposit = 0;
    annualInterest = 0;
    numberOfYears = 0;
}

// Setters and getters for class variables
void InvestmentData::setInitialAmount(int amount) {
    this->initialAmount = amount;
}

int InvestmentData::getInitialAmount() const {
    return this->initialAmount;
}

void InvestmentData::setMonthlyDeposit(int deposit) {
    this->monthlyDeposit = deposit;
}

int InvestmentData::getMonthlyDeposit() const {
    return this->monthlyDeposit;
}

void InvestmentData::setAnnualInterest(int interest) {
    this->annualInterest = interest;
}

int InvestmentData::getAnnualInterest() const {
    return this->annualInterest;
}

void InvestmentData::setNumberOfYears(int years) {
    this->numberOfYears = years;
}

int InvestmentData::getNumberOfYears() const {
    return this->numberOfYears;
}

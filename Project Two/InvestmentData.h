// InvestmentData class manages financial data for investment projections
class InvestmentData
{
private:
	// Initial amount invested at the start
	int initialAmount;

	// Amount deposited monthly
	int monthlyDeposit;

	// Annual interest rate (percentage)
	int annualInterest;

	// Number of years the investment is held
	int numberOfYears;

public:
	// Default constructor - initializes all values to zero
	InvestmentData();

	// Sets the initial investment amount
	void setInitialAmount(int amount);

	// Returns the initial investment amount
	int getInitialAmount() const;

	// Sets the monthly deposit amount
	void setMonthlyDeposit(int deposit);

	// Returns the monthly deposit amount
	int getMonthlyDeposit() const;

	// Sets the annual interest rate
	void setAnnualInterest(int interest);

	// Returns the annual interest rate
	int getAnnualInterest() const;

	// Sets the number of investment years
	void setNumberOfYears(int years);

	// Returns the number of investment years
	int getNumberOfYears() const;
};

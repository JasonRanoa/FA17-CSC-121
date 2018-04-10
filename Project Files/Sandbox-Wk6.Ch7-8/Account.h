// Account.h is the Account class specification file.
class Account
{
private:
    double balance;
    double intRate;
    double interest;
    int depositTransactions;
    int withdrawalTransactions;

public:

    // Constructor
    Account(double rate = 0.045, double bal = 0.0) {
        balance = bal;  intRate = rate;
        interest = 0.0; depositTransactions = 0;
        withdrawalTransactions = 0;
    }

    void makeDeposit(double amount) {
        balance += amount;
        depositTransactions++;
    }

    bool withdraw(double amount);  // Defined in account.cpp

    void calcInterest() {
        interest = balance * intRate;
        balance += interest;
    }

    double getBalance() { return balance; }
    double getInterest() { return interest; }

    int getDepositTransactions() { return depositTransactions; }
    int getWithdrawalTransactions() { return withdrawalTransactions; }
    int getTransactions() {
        return depositTransactions + withdrawalTransactions;
    }
};

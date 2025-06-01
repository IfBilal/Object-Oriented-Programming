#include <iostream>
#include <vector>
using namespace std;
class Account
{
protected:
    double balance;

public:
    Account(double b = 0.0)
    {
        if (b < 0)
        {
            balance = 0;
            cout << "Invalid initial balance";
        }
        else
            balance = b;
    }
    virtual void credit(double amount)
    {
        if (amount < 0)
        {
            cout << "Invalid amount\n";
            return;
        }
        balance += amount;
    }
    virtual void debit(double amount)
    {
        if (amount > balance)
        {
            cout << "Not Enough balance\n";
            return;
        }
        balance -= amount;
    }
    double getBalance() const
    {
        return balance;
    }
};
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double balance, double interestRate) : Account(balance), interestRate(interestRate) {}
    double calculateInterest()
    {
        return balance * interestRate;
    }
};
class CheckingAccount : public Account
{
private:
    double feePerTransaction;

public:
    CheckingAccount(double balance, double fee) : Account(balance), feePerTransaction(fee) {}
    void credit(double amount) override
    {
        if (amount < 0)
        {
            cout << "Invalid amount\n";
            return;
        }
        if (balance + amount - feePerTransaction < 0)
        {
            cout << "Not enough balance for transaction fee" << endl;
            return;
        }
        balance = balance + amount - feePerTransaction;
    }
    void debit(double amount) override
    {
        if (amount + feePerTransaction > balance)
        {
            cout << "Not Enough balance\n";
            return;
        }
        balance = balance - amount - feePerTransaction;
    }
};
int main()
{
    vector<Account *> acc;
    acc.push_back(new SavingsAccount(200, 2));
    acc.push_back(new CheckingAccount(300, 5));
    double amount;
    cout << "Balance in Savings account is : " << acc[0]->getBalance() << endl;
    cout << "Enter amount to credit in savings acc : ";
    cin >> amount;
    acc[0]->credit(amount);
    cout << "Balance in Savings account is : " << acc[0]->getBalance() << endl;
    cout << "Enter amount to debit in savings acc : ";
    cin >> amount;
    acc[0]->debit(amount);
    cout << "Balance in Savings account is : " << acc[0]->getBalance() << endl<<endl<<endl;

    cout << "Balance in checkings account is : " << acc[1]->getBalance() << endl;
    cout << "Enter amount to credit in checkings acc : ";
    cin >> amount;
    acc[1]->credit(amount);
    cout << "Balance in checkings account is : " << acc[1]->getBalance() << endl;
    cout << "Enter amount to debit in checkings acc : ";
    cin >> amount;
    acc[1]->debit(amount);
    cout << "Balance in checkings account is : " << acc[1]->getBalance() << endl;
}
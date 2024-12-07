#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"


static int closedAmounts[8];
static int closedAccountCount = 0;


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
    _accountIndex = _nbAccounts;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created" << std::endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";created" << std::endl;
}

Account::~Account() {
    static int initialAccountCount = _nbAccounts;

    closedAmounts[closedAccountCount] = _amount;
    closedAccountCount++;
    _totalAmount -= _amount;
    _nbAccounts--;

    if (closedAccountCount == initialAccountCount)
    {
        for (int i = 0; i < closedAccountCount; i++) 
        {
            _displayTimestamp();
            std::cout << "index:" << i
                      << ";amount:" << closedAmounts[closedAccountCount - 1 - i]
                      << ";closed" << std::endl;
        }
    }
}

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
            << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";deposit:" << deposit
            << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const{
    return _amount;
}

void Account::displayStatus(void) const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
    std::time_t now = std::time(0);
    std::tm* ltm = std::localtime(&now);
    
    std::cout << "[" 
            << 1900 + ltm->tm_year
            << std::setfill('0') 
            << std::setw(2) << 1 + ltm->tm_mon
            << std::setw(2) << ltm->tm_mday 
            << "_"
            << std::setw(2) << ltm->tm_hour
            << std::setw(2) << ltm->tm_min
            << std::setw(2) << ltm->tm_sec 
            << "] ";
}

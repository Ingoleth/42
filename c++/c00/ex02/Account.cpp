#include "Account.hpp"
#include <iostream>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _totalAmount += initial_deposit;
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "created" << std::endl;
    _nbAccounts++;
}

Account::Account(void)
{
    _totalAmount = 0;
    _accountIndex = 0;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount <<";";
    std::cout << "closed" << std::endl;

}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _totalNbDeposits << ";";
    std::cout << "total;" << _totalAmount <<";";
    std::cout << "deposits:" << _totalNbDeposits <<";";
    std::cout << "withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;

}

void	Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
    if (_amount > withdrawal)
    {
        _amount -= withdrawal; //Remove from total?
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        return (true);
    }
    //withdrawal = -1?
    return (false);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount;" << _amount <<";";
    std::cout << "deposits:" << _nbDeposits <<";";
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
    std::cout << "[";
    std::cout << "19920104_091532";
    std::cout << "] ";
}
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
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount <<";";
	std::cout << "deposits:" << _totalNbDeposits <<";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;

}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount <<";";
	std::cout << "deposit:" << deposit <<";";
	std::cout << "amount:" << _amount + deposit <<";";
	std::cout << "nb_deposits:" << _nbDeposits + 1;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << std::endl;

}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount <<";";
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal <<";";
	std::cout << "amount:" << _amount - withdrawal <<";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals + 1;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << std::endl;
	return (true);

}

int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount <<";";
	std::cout << "deposits:" << _nbDeposits <<";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;

}

void	Account::_displayTimestamp( void )
{
	char timestamp[19];
	std::time_t time = std::time(NULL);
	std::strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", std::localtime(&time));
	std::cout << timestamp;
}
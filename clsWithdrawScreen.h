#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsWithdrawScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadAccountNumber()
	{
		cout << "\nPlease Enter Account Number : ";
		return clsInputValidate::ReadString();

	}


public:

	static void ShowWithdrawScreen()
	{

		_DrawScreenHeader("\t    Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] dosen't found\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease Enter The Amount To Withdraw : ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure you want to perform this transaction ? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Client.Withdraw(Amount);
			cout << "\nAmount Withdrawed Successfuly \n";
			cout << "\nNew Balance is : " << Client.AccountBalance;
		}
		else
		{
			cout << "\n Operation was cancelled. \n";
		}
	}
};


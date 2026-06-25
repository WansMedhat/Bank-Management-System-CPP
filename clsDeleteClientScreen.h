#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
class clsDeleteClientScreen:protected clsScreen
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

public:

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccesRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		vector<clsBankClient>vClient = clsBankClient::GetClientsList();

		string Title = "\tDelete Client Screen";
		string SubTitle = "\t(" + to_string(vClient.size()) + ")Clients";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\nPlease Enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nAccount is Not Exist , Enter Another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		
		cout << "\nAre You Sure Do You Want To Delete This Client ? \n";

		char Answer = 'y';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";

				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}
		}
	}
};


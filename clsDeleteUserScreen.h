#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
class clsDeleteUserScreen:protected clsScreen
{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void ShowDeleteScreen()
	{
		string Title = "\t   Delete User Screen";
		_DrawScreenHeader(Title);

		cout << "\nPlease Enter Username : ";
		string Username = clsInputValidate::ReadString();


		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nPlease Enter Account Number : ";
			Username = clsInputValidate::ReadString();

		}
		
		clsUser User = clsUser::Find(Username);

		_PrintUser(User);

		char Answer = 'n';
		cout << "\n\n Are You Sure do You Want to Delete this User ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{ 
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully !\n";
				_PrintUser(User);
			}
			else
			{
				cout << "\nError User Was not Deleted \n";
			}

		}

	}

};


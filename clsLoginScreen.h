#pragma once
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsScreen.h"
#include"Global.h"
class clsLoginScreen:protected clsScreen
{


private:

	static bool _Login()
	{

		bool LoginFailed = false;

		short FailedLoginCount = 0;

		string Username, Password;

		do
		{
			
			if (LoginFailed)
			{
				FailedLoginCount++;
				cout << "\nInvalid Username / Password ! \n";
				cout << "You have " << (3 - FailedLoginCount) << " Trail(s) to Login";
			}

			if (FailedLoginCount >= 3)
			{
				cout << "\n\n\nYou are Locked after 3 failed trails\n\n\n";
				return false;
			}

			cout << "\nEnter Username : ";
			Username = clsInputValidate::ReadString();

			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();


			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
	}

public:

	static bool ShowLoginScreen()
	{
		
		system("cls");
		_DrawScreenHeader("\t   LoginScreen");
		return _Login();
	}
};


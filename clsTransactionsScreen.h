#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
class clsTransactionsScreen :protected clsScreen
{
private:
    enum enTransactionMenueOptions {
        eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,eTransfer = 4 ,eTransferLog = 5,eMainMenu = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
        //cout << "\nDepositScreen Will be here...\n";

        clsDepositScreen::ShowDepositScreen();

    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\nWithdrawScreen Will be here...\n";
        clsWithdrawScreen::ShowWithdrawScreen();

    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\nTotalBalancesScreen Will be here...\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {

        clsTransferScreen::ShowTransferScreen();

    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _PerfromTransactionsMenueOption(enTransactionMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionMenueOptions::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionMenueOptions::eMainMenu:
        {
            

        }
        }
    }
public:

    static void ShowTransactionsMenue()
    {

        if (!CheckAccesRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalaces.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionsMenueOption((enTransactionMenueOptions)_ReadTransactionsMenueOption());
    }
};


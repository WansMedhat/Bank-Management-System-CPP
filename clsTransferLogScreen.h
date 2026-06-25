#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsTransferLogScreen:protected clsScreen
{

private:

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferRecord TransferRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << TransferRecord.DateTime;
        cout << "| " << setw(10) << left << TransferRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferRecord.Amount;
        cout << "| " << setw(10) << left << TransferRecord.srcBalanceAfter;
        cout << "| " << setw(10) << left << TransferRecord.destBalanceAfter;
        cout << "| " << setw(10) << left << TransferRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {

        vector <clsBankClient::stTransferRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferRecord Record : vTransferLogRecord)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};


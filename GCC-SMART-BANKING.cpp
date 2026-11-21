#include <iostream>

using namespace std;

int MAX_USERS = 100;
int MAX_TRANSACTIONS = 1000;

//Amount of BANK ACCOUNTS TO PROCESS
int USERS = 0;

string Name;
string Surname;
int AccountNumber;
int Pin;
double Balance;
double SavingsBalance;

//TRANSACTION HISTORY
int HistoryUser;
string HistoryDetails;
double HistoryAmount;
int HistoryCount = 0;


//FINDACCOUNT
int findAccount(int AccountNumber)
 {
    for (int i = 0; i <USERS; i++)
    {
        if (AccountNumber == AccountNumber)
       return i;
    }
 }

 //SAVE TRANSACTION
 void addTransaction (int users, string details, double amount)
 {
     if (HistoryCount < MAX_TRANSACTIONS)
     {
         HistoryUser = users;
         HistoryDetails = details;
         HistoryAmount = amount;
         HistoryCount++;
     }
     else{
        cout<<"Transaction History Is Full."<<endl;
     }
 }

 //REGISTERUSER!
 void registerUSERS()
 {
     cout<<"Enter The Amount Of Bank Accounts To Process: ";
     cin>>USERS;

     if (USERS >MAX_USERS)
     {
         USERS = MAX_USERS;
         cout<< "Limit Reached. Seeting Max Accounts to " <<MAX_USERS<<endl;
     }

     for (int i = 0; i < USERS; i++)
     {
         cout<<"===================== REGISTER USERS ===================="<<endl;
         cout<<"Enter Name: ";
         cin>>Name;
         cin>>Surname;

         cout<<"Enter Account Number: ";
         cin>>AccountNumber;

         cout<<"Enter PIN: ";
         cin>>Pin;

         cout<<"Enter Balance: R";
         cin>>Balance;

         SavingsBalance=0;
         while (Balance <0)
         {
             cout<<"Balance Cannot Be Negative. Enter Again: R";
             cin>>Balance;
         }
     cout<<"All Accounts Registered SUCCESSFULLY"<<endl;
     }
     cout<<"Alll ACCOUNTS REGISTERED SUCCESSFULLY!"<<endl;

 }

 //CHECK TRANSACTION HISTORY
 void TransactionHistory(int user)
 {
     cout<<"======================= TRANSACTIN HISTORY ========================="<<endl;

     bool found = false ;
         for (int i = 0; i < HistoryCount; i++)
    {
        if (HistoryUser == user)
        {
            cout << "Transaction: " << HistoryDetails << endl;

            cout << "Amount: R"
                 << HistoryAmount << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No Transactions Found." << endl;
    }
}

// SAVINGS ACCOUNT
void SavingsAccount(int user)
{
    int choice;
    double amount;

    do
    {
        cout << "========== SAVINGS ACCOUNT ==========" << endl;
        cout << "1. Check Savings Balance" << endl;
        cout << "2. Deposit Into Savings" << endl;
        cout << "3. Withdraw From Savings" << endl;
        cout << "4. Return To Banking Menu" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Your Savings Balance: R"
                 << SavingsBalance << endl;
            break;

        case 2:
            cout << "Enter Amount To Save: R";
            cin >> amount;

            if (amount > 0 && amount <= Balance)
            {
                Balance -= amount;
                SavingsBalance += amount;

                addTransaction(user, "Deposit Into Savings", amount);

                cout << "Successfully Saved R" << amount << endl;
            }
            else
            {
                cout << "Invalid Amount Or Insufficient Funds." << endl;
            }
            break;

        case 3:
            cout << "Enter Amount To Withdraw From Savings: R";
            cin >> amount;

            if (amount > 0 && amount <= SavingsBalance )
            {
                SavingsBalance -= amount;
                Balance += amount;

                addTransaction(user, "Withdrawal From Savings", amount);

                cout << "Successfully Withdrawn R" << amount << endl;
            }
            else
            {
                cout << "Insufficient Savings Balance." << endl;
            }
            break;

        case 4:
            cout << "Returning To Banking Menu..." << endl;
            break;

        default:
            cout << "Invalid Choice." << endl;
        }

    } while (choice != 4);
}

// BUY AIRTIME
void BuyAirtime(int user)
{
    int networkChoice;
    string network;
    string phoneNumber;
    double amount;

    cout << "========== BUY AIRTIME ==========" << endl;

    cout << "1. Telkom" << endl;
    cout << "2. Vodacom" << endl;
    cout << "3. MTN" << endl;
    cout << "4. Cell C" << endl;

    cout << "Select Network: ";
    cin >> networkChoice;

    switch (networkChoice)
    {
    case 1:
        network = "Telkom";
        break;

    case 2:
        network = "Vodacom";
        break;

    case 3:
        network = "MTN";
        break;

    case 4:
        network = "Cell C";
        break;

    default:
        cout << "Invalid Network Selection." << endl;
        return;
    }

    cout << "Enter Cellphone Number: ";
    cin >> phoneNumber;

    if (phoneNumber.length() != 10)
    {
        cout << "Invalid Phone Number." << endl;
        return;
    }

    cout << "Enter Airtime Amount: R";
    cin >> amount;

    if (amount > 0 && amount <= Balance )
    {
        Balance -= amount;

        addTransaction(user, "Airtime Purchase - " + network, amount);

        cout << "AIRTIME PURCHASE SUCCESSFUL!" << endl;
        cout << "Network: " << network << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Airtime Amount: R" << amount << endl;
        cout << "Remaining Balance: R" << Balance << endl;
    }
    else
    {
        cout << "Invalid Amount Or Insufficient Funds." << endl;
    }
}

 //BANKING MEUN (DEPOSIT, WITHDRAWALS, BALANCE)
 void BankingMenu(int user)
{
    int choice;

    do
    {
        cout << "========================================" << endl;
        cout << "             GCC BANK MENU              " << endl;
        cout << "========================================" << endl;

        cout << "Welcome, " << Name << " "
             << Surname << endl;

        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Send Cash" << endl;
        cout << "5. Transaction History" << endl;
        cout << "6. Savings Account" << endl;
        cout << "7. Buy Airtime" << endl;
        cout << "8. Logout" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Current Balance: R"
                 << Balance << endl;
            break;

        case 2:
        {
            double DepositAmount;

            cout << "Enter Amount To Deposit: R";
            cin >> DepositAmount;

            if (DepositAmount > 0)
            {
                Balance += DepositAmount;

                addTransaction(user, "Money Deposit", DepositAmount);

                cout << "Successfully Deposited R"
                     << DepositAmount << endl;

                cout << "New Balance: R"
                     << Balance << endl;
            }
            else
            {
                cout << "Invalid Amount." << endl;
            }
            break;
        }

        case 3:
        {
            double WithdrawalAmount;

            cout << "Enter Amount To Withdraw: R";
            cin >> WithdrawalAmount;

            if (WithdrawalAmount > 0 &&
                WithdrawalAmount <= Balance)
            {
                Balance -= WithdrawalAmount;

                addTransaction(user, "Money Withdrawal",
                               WithdrawalAmount);

                cout << "Successfully Withdrawn R"
                     << WithdrawalAmount << endl;

                cout << "New Balance: R"
                     << Balance << endl;
            }
            else
            {
                cout << "Invalid Amount Or Insufficient Funds." << endl;
            }
            break;
        }


case 4:
{
    int recipientAccount;
    double TransferAmount;

    cout << "========== SEND CASH ==========" << endl;

    cout << "Enter Recipient Account Number: ";
    cin >> recipientAccount;

    // SEARCH FOR RECIPIENT ACCOUNT
    int recipientIndex = findAccount(recipientAccount);

    if (recipientIndex == -1)
    {
        cout << "Account Number Not Found." << endl;
    }
    else if (recipientIndex == user)
    {
        cout << "You Cannot Send Money To Your Own Account." << endl;
    }
    else
    {
        cout << "Recipient Name: "
             << Name[recipientIndex] << " "
             << Surname[recipientIndex] << endl;

        cout << "Enter Amount To Send: R";
        cin >> TransferAmount;

        if (TransferAmount > 0 &&
            TransferAmount <= Balance)
        {
            // DEDUCT MONEY FROM SENDER
            Balance -= TransferAmount;

            // ADD MONEY TO RECIPIENT
            Balance += TransferAmount;

            // RECORD TRANSACTIONS
            addTransaction(user, "Cash Transfer Sent",
                           TransferAmount);

            addTransaction(recipientIndex,
                           "Cash Transfer Received",
                           TransferAmount);

            cout << "\nTRANSFER SUCCESSFUL!" << endl;

            cout << "Money Sent To: " << Name[recipientIndex] << " " << Surname[recipientIndex] << endl;

            cout << "Amount Sent: R"
                 << TransferAmount << endl;

            cout << "Your New Balance: R"
                 << Balance << endl;
        }
        else
        {
            cout << "Invalid Amount Or Insufficient Funds."
                 << endl;
        }
    }

    break;
}
        case 5:
            TransactionHistory(user);
            break;

        case 6:
            SavingsAccount(user);
            break;

        case 7:
            BuyAirtime(user);
            break;

        case 8:
            cout << "Logging Out..." << endl;
            break;

        default:
            cout << "Invalid Choice. Please Try Again." << endl;
        }

    } while (choice != 8);
}





void Login()
{
    int enteredAccountNumber;
    int enteredPin;

    cout<<"==================== GCC BANK LOGIN ======================"<<endl;
    cout<<"Enter Account Number: ";
    cin>> enteredAccountNumber;
    cout<<"Enter Pin: ";
    cin>>enteredPin;

    for (int i = 0; i<USERS; i++){
        if (AccountNumber == enteredAccountNumber && Pin == enteredPin)
        {
            cout<< "WELCOME, " <<Name << Surname<<endl;
            BankingMenu(0);
        }
    }
   return;
}

int main()
{
    cout<< fixed;
    registerUSERS();

    if (USERS == 0)
    {
        cout << "No Accounts Registered. Program Closing." << endl;
        return 0;
    }

    int choice;

    do
    {
        cout << "===================================" << endl;
        cout << "          GCC BANK                 " << endl;
        cout << "===================================" << endl;

        cout << "1. Login To Account" << endl;
        cout << "2. Exit" << endl;

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Login();
            break;

        case 2:
            cout << "Thank You For Using GCC BANK. GOODBYE!" << endl;
            break;

        default:
            cout << "Invalid Choice. Please Try Again." << endl;
        }

    } while (choice != 2);

    return 0;
}

#include <iostream>
#include "Account.h"
using namespace std;

void menu();
void create(Account *acc_ptr[]);


int main()
{
    // Declare an array of Account pointers.
    // The array can hold up to five Account objects.
    Account *acc_ptr[5];

    // Don't forget to initialize the pointers with nullptr.
    for (int i=0; i < 5; i++)
    {
        acc_ptr[i] = nullptr;
    }

    // Create a new Account object and assign it to acc_ptr[0]
    acc_ptr[0] = new Account;
    acc_ptr[0]->setAccount("Alice", 1234, 1, 1000.00);
    acc_ptr[0]->withdrawal(550);
    acc_ptr[0]->displayAccountInfo();
    
    // Create second Account object and assign it to acc_ptr[2]
    Account * ptr;
    ptr = new Account;
    ptr->setAccount("Bob", 2345, 2, 2000);
    acc_ptr[2] = ptr;
    (*acc_ptr[2]).displayAccountInfo(); // Or acc_ptr[2]->displayAccountInfo();
    
    // Delete the first Account object
    delete acc_ptr[0];
    acc_ptr[0] = nullptr;
    
    // Delete the second Account object
    delete acc_ptr[2];
    acc_ptr[2] = nullptr;
    
    // lab10-----------------------------------------------------------------
    cout << "lab 10 test cases " << endl; 
    menu(); 
    
    int toDelete; 
    int option; 
    
    cout << "Enter your option: "; 
    cin >> option; 

    
    while(option != 3)
    {
        if(option == 1)
        {
            create(acc_ptr);
            cout << acc_ptr;
        }
        if(option == 2)
        {
            cout << "Enter account number to delete: ";
            cin >> toDelete; 
            for(int i =0 ; i < 5 ; i++)
            {
                cout << acc_ptr[i]->getNum(); 
                if(acc_ptr[i]->getNum() == toDelete)
                {
                    delete acc_ptr[i];
                    acc_ptr[i] = nullptr;
                }
            }
        }
        if(option == 3)
        {
            return 0; 
        }
        
        cout << endl << endl << "Enter your option: "; 
        cin  >> option; 
        
    }
    

    
    return 0;
}



void create(Account *acc_ptr[])
{
    string k1; 
    int k2, k3;
    double k4;
    int index; 
    for(int i = 0 ; i < 5; i++ )
    {
        
        if(acc_ptr[i] == nullptr)
        {
            index = i ; 
            break; 
        }
    }
    cout << "Enter a name: "; 
        cin >> k1; //ACCNAME
    cout << "Enter an account number: "; 
        cin >> k2; //ACCNUM
    cout << "Enter a type: ";
        cin >> k3; //ACCTYPE
    cout << "Enter an initial balance: ";  
        cin >> k4; //ACCBAL
    // Create a new Account object and assign it to acc_ptr[index]
    acc_ptr[index] = new Account;
    acc_ptr[index]->setAccount(k1, k2, k3, k4);
    acc_ptr[index]->displayAccountInfo();
    
}

void menu()
{
    cout << " =========================" 
         << endl << "   Program Menu: "
         << endl << " 1: Open  Account "
         << endl << " 2: Close Account "
         << endl << " 3: Exit  Account "
         << endl << endl; 
}
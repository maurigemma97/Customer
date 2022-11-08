//Some extra additions I could make in the future is making sure a valid date is given, no duplicate ID's can exist, no negative zipcodes can be given
//Lastly, name string must not contain numbers 


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int MAXCUST = 30; //max of 30 customers


struct Customer
{
   // int numCust = 0;
    int id;
    string name;
    string zip;
    double balance;
    string lastPay;
    
    void addcust(Customer customerarray[], int numCust);  //add a new customer to the array if their is room
    void updatecust(Customer customerarray[], int numCust); //update the customer information if the given id number is valid
    int findcust(Customer customerarray[], int numCust, int idnum); //linear search until customer id that is passed in argument is found
    void printarray(Customer customerarray[],int numCust); //prints the contents of the array
    void setarray(Customer customerarray[]); //Intialize the array
};

int getmenu();


int main()
{
    
    Customer mycustomerarray[30]; //Create object array of 30
    int currentNum = 0;  //Intialize number of customers
    
    
    mycustomerarray[0].setarray(mycustomerarray);  //Intialize the array
                                                    //Constructor also could have done same thing
    
    
    
    
    //int numCust = 0;
    int get_my_choice;
    while(get_my_choice)
    {
        get_my_choice = getmenu();
        
    
        if(get_my_choice == 1)
        {
            if(currentNum > MAXCUST) //checks to see if the number of customers exceeds the max amount
            {
                cout << "No room" << endl;
            }
            else
            {
                mycustomerarray[currentNum].addcust(mycustomerarray,currentNum); //will add customer to current position of array and then increment it
                currentNum++;
            }
        
        }
        else if(get_my_choice == 2)
        {
                mycustomerarray[currentNum].updatecust(mycustomerarray,currentNum); //update current customer info
        }
        else if(get_my_choice == 3)
        {
            
            
                mycustomerarray[currentNum].printarray(mycustomerarray,currentNum); //prints the customers in the array
            
            
        }
        else if(get_my_choice == 4)
        {
            exit(0); //exit program
        }
    }
    
	return 0;
}

int getmenu()
{
    int choice;
   // bool indicator = true;
    
    cout << "1.Enter new account information" << endl;
    cout << "2.Change account information" << endl;
    cout << "3.Display all account information" << endl;
    cout << "4.Exit the program" << endl;
    cout << endl;
    cout << "Enter your choice" << endl;
    cin >> choice;
    
    while(choice > 4 || choice < 1) //validate that number is between 1-4
    {
        
            cout << "Invalid number entered" << endl;
            cin >> choice;
        
    }
    cout << "your choice:" << " " << choice << endl;
    return choice;
    
    
}


void Customer::addcust(Customer customerarray[], int numCust)
{
    //bool balancecheck = true;
    //bool idcheck = true;
    
    
    if(customerarray[numCust].name == " ") //if their is space in that current part of array then you are allowed to add a customer
    {
            cout << "Enter ID number:" << endl;
            cin >> customerarray[numCust].id;
            while(customerarray[numCust].id < 0)
            {
                
                    cout << "ID must be positive" << endl; //interger value must be positive
                    cout << "Enter ID Number:" << endl;
                    cin >> customerarray[numCust].id;
                
        
            }
            cin.ignore();
            cout << "Enter Name:" << endl;
            getline(cin,customerarray[numCust].name);
            cout << "Enter Zipcode:" << endl;
            getline(cin,customerarray[numCust].zip);
            
            cout << "Enter Account Balance:" << endl;
            cin >> customerarray[numCust].balance;
            while(customerarray[numCust].balance < 0) //make sure balance isnt negative
            {
               
                    cout << "Balance Must Be Positive" << endl;
                    cout << "Enter Account Balance Again:" << endl;
                    cin >> customerarray[numCust].balance;
            }
                
            
                
            
            //cin >> customerarray[numCust].balance;
            cin.ignore();
            cout << "Enter Last Payment Date:" << endl;
            getline(cin,customerarray[numCust].lastPay);
            
    }
    else
    {
        cout << "No Room" << endl; //this message will display if no room is available in the array
    }
    
   
    
}

void Customer::printarray(Customer customerarray[],int numCust)
{
    cout << left << setw(15) << "ID Number" << setw(8) << "Name" << setw(8) << "Zipcode" << setw(8) << "Balance" << setw(8) << "Date of Payment" << endl;
    cout << left << setw(15) << "______" << setw(8) << "______" << setw(8) << "_________" << setw(8) << "_________" << setw(8) << "_________________" << endl;
    for(int i = 0; i < numCust; i++)
    {
        cout << left << setw(15) << customerarray[i].id << setw(8) << customerarray[i].name << setw(8) << customerarray[i].zip << setw(8) 
        << customerarray[i].balance << setw(8) << customerarray[i].lastPay << endl;
    }
}

void Customer::setarray(Customer customerarray[])
{
    for(int i = 0; i < MAXCUST; i++)
    {
        customerarray[i].name = " ";
        customerarray[i].id = 0;
        customerarray[i].balance = 0;
        customerarray[i].lastPay = " ";
        customerarray[i].zip = " ";
    }
}

void Customer:: updatecust(Customer customerarray[], int numCust)
{
    int input;
    int customerIDnumber;
    cout << "Please enter your ID number:" << endl;
    cin >> input;
    customerIDnumber = findcust(customerarray,numCust, input);
    
    if(customerIDnumber == -1)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Customer was found" << endl;
        cout << "Enter new information" << endl;
        cout << "Enter ID Number:" << endl;
        cin >> customerarray[customerIDnumber].id;
        while(customerarray[customerIDnumber].id < 0) //must update with positive ID
        {
            cout << "Must be positive ID number" << endl;
            cout << "Enter ID Number Again:" << endl;
            cin >> customerarray[customerIDnumber].id;
        }
        cin.ignore();
        cout << "Enter Name:" << endl;
        getline(cin,customerarray[customerIDnumber].name);
        cout << "Enter Zipcode:" << endl;
        getline(cin,customerarray[customerIDnumber].zip);
        cout << "Enter Account Balance:" << endl;
        cin >> customerarray[customerIDnumber].balance;
        while(customerarray[customerIDnumber].balance < 0) //must update with positive account balance
        {
            cout << "Balance must be positive" << endl;
            cout << "Enter Account Balance Again:" << endl;
            cin >> customerarray[customerIDnumber].balance;
        }
        cin.ignore();
        cout << "Enter Your Last Date Of Payment:" << endl;
        getline(cin,customerarray[customerIDnumber].lastPay);
        
        
        
    }
    cout << "Account is updated!" << endl;
    
    
}

int Customer::findcust(Customer customerarray[], int numCust, int idnum)
{
    for(int i = 0; i < numCust; i++)
    {
        if(customerarray[i].id == idnum) //run linear search and return psoition of the customer when it matches the id
        {                                  
            return i;
        }
    
    }
    return -1; //return -1 if customer is not found
}
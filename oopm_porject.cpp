#include <iostream>
#include <string>
using namespace std;
class details 
{
    public:
    int phone_no;
    string name;
    int credit_card;
    int debit_card, pin;
    string UPI,st;
    int num, op, n;
    
};
class railway:public details
{
public:
    static int A1; // first ac
    static int A2; // second ac
    static int A3; // third ac
    static int SL; // sleeper seats

public:
    void booking();
    void information();
};
int railway ::A1 = 50;
int railway ::A2 = 50;
int railway ::A3 = 50;
int railway ::SL = 150;

class ticket : public railway
{
public:
    void search(ticket s[300]);
    void update(ticket s[300]);
    void deletel(ticket s[300]);
    void displayoperations(ticket s[300]);
    void displayseats();
    void show(ticket s[300]);
};

void ticket::displayoperations(ticket s[300])
{
    cout << "Enter '1' for ticket booking " << endl;
    cout << "Enter '2' for search your ticket " << endl;
    cout << "Enter '3' for delete your ticket " << endl;
    cout<<"Enter '4' for update your information"<< endl;
    cin >> op;
    switch (op)
    {
    case 1:
        booking();
        break;
    case 2:
        search(s);
        break;
    case 3:
        deletel(s);
        break;
        case 4:
        update(s);
        break;
    default:
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! You entered the wrong number !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ";
        break;
    }
}

void ticket::displayseats()
{
    cout << "Available seats are : " << endl;
    cout << "First AC = " << A1 << endl;
    cout << "Second AC = " << A2 << endl;
    cout << "Third AC = " << A3 << endl;
    cout << "Sleeper seats = " << SL << endl;
}

void railway::booking()
{
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! If you want to book a ticket !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
         << "Enter 1 for first AC" << endl
         << "Enter 2 for second AC " << endl
         << "Enter 3 for third AC" << endl
         << "Enter 4 for sleeper class" << endl;
    cin >> num;
    switch (num)
    {
    case 1:
        if (A1 > 0)
        {
            --A1;
            cout << "******************************************** You selected first AC *********************************************" << endl;
            information();
        }
        else
        {
            cout << "First AC seats are not available." << endl;
        }
        break;
    case 2:
        if (A2 > 0)
        {
            --A2;
            cout << "********************************************* You selected second AC ***********************************************" << endl;
            information();
        }
        else
        {
            cout << "Second AC seats are not available." << endl;
        }
        break;
    case 3:
        if (A3 > 0)
        {
            --A3;
            cout << "********************************************* You selected third AC *************************************************" << endl;
            information();
        }
        else
        {
            cout << "Third AC seats are not available." << endl;
        }
        break;
    case 4:
        if (SL > 0)
        {
            --SL;
            cout << "************************************************ You selected sleeper class *******************************************" << endl;
            information();
        }
        else
        {
            cout << "Sleeper class seats are not available." << endl;
        }
        break;
    default:
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! You entered the wrong number !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        break;
    }
}

void ticket::search(ticket s[300])
{
    string naam;
    int mobile_no;
    cout << "Enter your name: ";
    cin >> naam;
    for (int m = 0; m < 300; m++)
    {
        if (naam == s[m].name)
        {
            cout << "Enter your registered phone number: ";
            cin >> mobile_no;
            for (int t = 0; t < 300; t++)
            {
                if (mobile_no == s[t].phone_no)
                {
                    cout << "Your seat is booked." << endl;
                    return;
                }
            }
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!! Phone number not found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! No such name found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}
void ticket::update(ticket s[300])
{
    string naam;
    int mobile_no;
    cout << "Enter your name: ";
    cin >> naam;
    for (int m = 0; m < 300; m++)
    {
        if (naam == s[m].name)
        {    
            cout << "Enter your registered phone number: ";
            cin >> mobile_no;
            for (int t = 0; t < 300; t++)
            {
                if (mobile_no == s[t].phone_no)
                {
                    cout << "Enter new name" << endl;
                    cin>>s[m].name;
                    cout<<"Enter new phone number"<<endl;
                    cin>>s[t].phone_no;
                    return;
                }
            }
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!! Phone number not found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! No such name found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}
void ticket::deletel(ticket s[300])
{
    string naam;
    int mobile_no;
    cout << "Enter your name: ";
    cin >> naam;
    for (int m = 0; m < 300; m++)
    {
        if (naam == s[m].name)
        {
            cout << "Enter your registered phone number: ";
            cin >> mobile_no;
            for (int t = 0; t < 300; t++)
            {
                if (mobile_no == s[t].phone_no)
                {
                    s[m].name = "";
                    s[t].phone_no = 0;
                    cout<<"Enter seat your seat type";
                    cin>>st;
                    if(st=="A1")
                    {
                        A1++;
                    }
                    else if(st=="A2")
                    {
                        A2++;
                    }
                    else if(st=="A3")
                    {
                        A3++;
                    }
                    else if(st=="SL")
                    {
                        SL++;
                    }
                    else {
                        cout<<"You entered wrong seat type";
                    }
                    cout << "Your seat is deleted." << endl;
                    return;
                }
            }
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Phone number not found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        }
    }
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! No such name found. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
}

void railway::information()
{
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your phone number: ";
    cin >> phone_no;
    cout << "Select payment method" << endl;
    cout << "Enter '1' for credit card " << endl;
    cout << "Enter '2' for debit card " << endl;
    cout << "Enter '3' for UPI " << endl;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Enter your credit card number: ";
        cin >> credit_card;
        cout << "Swipe your card in the device." << endl;
        cout << "Seat booked successfully." << endl;
        break;
    case 2:
        cout << "Enter your debit card number: ";
        cin >> debit_card;
        cout << "Enter your pin: ";
        cin >> pin;
        cout << "Seat booked successfully." << endl;
        break;
    case 3:
        cout << "Enter your UPI: ";
        cin >> UPI;
        cout << "Seat booked successfully." << endl;
        break;
    default:
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! You entered the wrong number. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        break;
    }
}

void ticket::show(ticket s[300])
{
    displayseats();
    displayoperations(s);
}

int main()
{
    int i;
    ticket r[300];
    for (i = 1; i <= 300; i++)
    {
        r[i].show(r);
    }
    cout << "***** Booking closed *****" << endl;
    return 0;
}

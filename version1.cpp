#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
void readdatafromFile();
void clear();
// to check whether the username valid or invalid
bool isvaliduserName(string user_name);
// functions for sign in
bool sign_in();
// function to view users
void view_users();
// to store data in files
void storeinfile(string user_name,string password);
// function for sign_up
void sign_up(string user_name,string password);
// function for main menu
string takechoice();
const int count1=50;
int count = 0;
// array for usernames
string usernames[count1];
// array for passwords 
string passwords[count1];

main()
{
    readdatafromFile();

    system("cls");    
    bool decision;
    string user_name;
    string password;
    string choice = "4";
    while(choice != "0")
    {
       choice = takechoice();
       if (choice == "1")
       {
             cout << "Enter the user name : " << endl;
             cin >> user_name;
             cout << "Enter the password : " << endl;
             cin >> password;
             decision = isvaliduserName(user_name);
             if (decision == true)
            {
                sign_up(user_name,password);
                storeinfile( user_name, password);
                cout << "user register successfully " << endl;
            }
            else
            {
                cout << "USer already registred  " << endl;

            }
            clear();
       }
       if (choice == "2")
       {
            decision=sign_in();
            if(decision == true)
            {
                cout << "Login Successfully " << endl;

            }
            else
            {
               cout << "Invalid Credientials " << endl;

            }
            clear();
        }
        if (choice == "3")
        {
            view_users();
            clear();
  
        }
    }

}
string takechoice()
{

    cout <<"#################################"<< endl;
    cout <<" 0             exit              "<< endl;
    cout <<" 1             sign_up           "<< endl;
    cout <<" 2             sign_in           "<< endl;
    cout <<" 3             view_user         "<< endl;
    cout <<"#################################"<< endl;
    
    cout << "enter the option : " << endl;
    string choice;
    cin >> choice;
    return choice;
    
}
void sign_up(string user_name,string password)
{
  usernames[count] = user_name;
  passwords[count] = password;
  count++; 


}
void storeinfile(string user_name,string password)
{
    fstream file;
    file.open("data.txt",ios::app);
    file << user_name << endl ;
    file <<  password << endl;;
    file.close();

}
void view_users()
{
    cout << "--------------------------------------" << endl;
    cout <<    "USERNAMES           PASSWORDS      " << endl;                  
    for(int index = 0;index<count ;index++)
    {
        cout << usernames[index] <<"               "<< passwords[index] << endl;
                                    
    }
    cout << "______________________________________" << endl;

}
bool sign_in()
{
    bool result = false;
    string Name;
    cout << "Enter your name : " << endl;
    cin >> Name;
    string Password;
    cout << "Enter your Password : " << endl;
    cin >> Password; 
    for(int index = 0;index<count ;index++)
    {

        if(usernames[index] == Name &&  passwords[index] == Password )
        {
            result = true;
            return result;
        }
        else
        {
            return result;
        }       

    }
    return 0;

}
bool isvaliduserName(string user_name)
{
    bool result = true;
    for(int index = 0;index<count ;index++)
    {

        if(usernames[index] == user_name)
        {
            result = false;
            break;
        }
      

    }
     return result;

}
void readdatafromFile()
{
    
    
    string name;
    string password;
    fstream file;
    file.open("data.txt" ,ios::in);
    while( getline(file,name) && getline(file,password))
    {
    usernames[count] = name;
    passwords[count] = password;
    count++;
    }
    file.close();
 

}
void clear()
{

    cout << "Press any key to continue....";
    getch();
    system("cls");

}
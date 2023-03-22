#include<iostream>
#include<fstream>
using namespace std;
main()
{
    int count=0;
    string name;
    fstream file;
    file.open("data.txt" ,ios::in);
    while(!file.eof())
    {

    
     getline(file,name);
   
       count++;
    
    }
    file.close();
    cout << count;
    
}   
#include<iostream>
#include<fstream>
using namespace std;
main()
{
    string name = "ali";
    fstream file;
    fileopen("data.txt" ,ios::out);
    file << name;
    file.close();
}
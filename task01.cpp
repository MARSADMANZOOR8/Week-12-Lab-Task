 #include<iostream>
 #include<fstream>
 using namespace std;
 main()
 {
   int user_name = 465635;
    fstream file;
    file.open("date.txt",ios::app);
    file << user_name;
    file.close();
 }